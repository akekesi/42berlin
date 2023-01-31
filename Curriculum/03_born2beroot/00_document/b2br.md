<base target="_blank">

# born2beroot
# Questions
* AppArmor status ???
* What is telnet ???
# Data
hostname: ```akekesi42```\
password: ```Password_b2br```

full name: ```attila kekesi```

usename: ```akekesi```\
password: ```Password_b2br```

encryption:\
password: ```Password_b2br```

MySQL:\
password: ```Password_b2br```

WordPress: ```akekesi```\
password: ```Password_b2br```\
WordPress: ```http://127.0.0.1:8080/```

# Links
[YouTube](https://www.youtube.com/watch?v=OQEdjt38ZJA) *(no audio)*\
[GitHub](https://github.com/ucefooo/born2beroot)\
[GitHub](https://github.com/mcombeau/Born2beroot)\
[Debian](https://www.debian.org)

# Table of Contents   
0. [Virtual Machine](#virtual-machine)
0. [*aptitude*](#aptitude)
0. [*sudo*](#sudo)
0. [SSH](#ssh)
0. [UFW](#ufw)
0. [Password Policy](#password-policy)
0. [AppArmor](#apparmor)
0. [Cron](#cron)
0. [WordPress](#wordpress)
0. [Fail2ban](#fail2ban)
0. [Telnet](#telnet)
0. [Train](#train)
0. [Star Wars](#star-wars)
0. [FTP](#ftp)
0. [Snapshot](#snapshot)
0. [Signature](#signature)
0. [Commands](#commands)
# Virtual Machine
[YouTube](https://www.youtube.com/watch?v=OQEdjt38ZJA) *(no audio)*
# *aptitude*
Install aptitude:
```
$ apt-get install aptitude
```
# *sudo*
Switch to *root*:
```
$ su -
Password:
```
or
```
$ su root
Password:
```
Install *sudo*:
```
$ apt install sudo
$ apt update
$ apt upgrade
```
Add user to sudo group:
```
$ adduser <username> sudo
```
or
```
$ usermod -aG sudo <username>
```
Check user was successfully added to sudo group
```
$ getent group sudo
```
Check *sudo* provoleges:
```
$ sudo whoami
root
```
If not root, modify sudoers file as explained below and add this line:
```
$ username  ALL=(ALL:ALL) ALL
```
Edit sudoers.tmp file as root:
```
$ sudo visudo
```
And add these default settings as per subject instructions;
```
Defaults     passwd_tries=3
Defaults     badpass_message="Wrong password. Try again!"
Defaults     logfile="/var/log/sudo/sudo.log"
Defaults     log_input
Defaults     log_output
Defaults     requiretty
```
If ```var/log/sudo``` directory does not exist:
```
$ mkdir var/log/sudo
```
Open sudo.log:
```
sudo nano /var/log/sudo/sudo.log
```
# SSH
Install OpenSSH:
```
$ sudo apt update
$ sudo apt upgrade
$ sudo apt install openssh-server
```
Check SSH status:
```
$ sudo systemctl status ssh
```
Change SSH listening port to 4242:
```
$ sudo nano /etc/ssh/sshd_config
```
Find this line:
```
#Port 22
```
Uncomment (delete #) and change it to:
```
Port 4242
```
Find this line:
```
#PermitRootLogin prohibit-password
```
Uncomment (delete #) and change it to:
```
PermitRootLogin no
```
Check SSH status via sudo service ssh status.
```
$ sudo service ssh status
```
or
```
$ systemctl status ssh
```
Add an UFW rule to allow port 4242 in VirtualBox.\
Select your VM >> ```Settings``` >> ```Network``` >> ```Adapter 1``` >> ```Advanced``` >> ```Port Forwarding```
- Add a rule with Host and Guest port ```4242```

Select your VM >> ```Settings``` >> ```Network``` >> ```Adapter 1```
- Attached to: Bridged Adapter
- Name: eno2

Restart SSH service after this change.
Reboot
```
$ su -
$ reboot
```
list IP addresses with colors
```
$ ip -c a
```
Connect (in terminal with external ip (global)):
```
$ ssh <username>@10.15.248.154 -p 4242
```
Quit the ssh connection
```
$ exit
```

# UFW
Install and enable UFW:
```
$ apt update
$ apt upgrade
$ apt install ufw
$ ufw enable
```
Allow port 4242:
```
$ ufw allow 4242
```
Check UFW status:
```
$ ufw status
```
Delete port
```
$ ufw delete <port_position_in_list>
```
# Password Policy
Modify lines in ```/etc/login.defs```:
```
sudo nano /etc/login.defs
```
```
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```
These changes aren't automatically applied to existing users, so use chage command to modify for any users and for root:
```
$ chage -M 30 <username or root>
$ chage -m 2 <username or root>
$ chage -W 7 <username or root>
```
Check user settings:
```
$ chage -l <username or root>
```
Install password quality verification library:
```
$ apt install libpam-pwquality
```
Modify ```/etc/security/pwquality.conf```:
```
nano /etc/security/pwquality.conf
```
```
difok = 7
minlen = 10
dcredit = -1
ucredit = -1
lcredit = -1
maxrepeat = 3
usercheck = 1
retry = 3
enforce_for_root
```
Change user passwords to comply with password policy:
```
$ passwd <user/root>
```
# AppArmor
To make sure AppArmor is installed:
```
$ aptitude search apparmor
```
If by any reason it is not installed, install and enable it at startup:
```
$ aptitude install apparmor
$ aa-status 
$ systemctl enable apparmor
```
# Cron
Create monitoring.sh file as root and put it in /root directory:
```
#!/bin/bash

ARCH=$(uname -srvmo)
PCPU=$(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
VCPU=$(grep processor /proc/cpuinfo | uniq | wc -l)
RAM_TOTAL=$(free -h | grep Mem | awk '{print $2}')
RAM_USED=$(free -h | grep Mem | awk '{print $3}')
RAM_PERC=$(free -k | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}')
DISK_TOTAL=$(df -h --total | grep total | awk '{print $2}')
DISK_USED=$(df -h --total | grep total | awk '{print $3}')
DISK_PERC=$(df -k --total | grep total | awk '{print $5}')
CPU_LOAD=$(top -bn1 | grep '^%Cpu' | xargs | awk '{printf("%.1f%%"), $2 + $4}')
LAST_BOOT=$(who -b | awk '{print($3 " " $4)}')
LVM=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
TCP=$(grep TCP /proc/net/sockstat | awk '{print $3}')
USER_LOG=$(who | wc -l)
IP_ADDR=$(hostname -I | awk '{print $1}')
MAC_ADDR=$(ip link show | grep link/ether | awk '{print $2}')
SUDO_LOG=$(grep COMMAND /var/log/sudo/sudo.log | wc -l)

wall "
       ------------------------------------------------
       Architecture    : $ARCH
       Physical CPUs   : $PCPU
       Virtual CPUs    : $VCPU
       Memory Usage    : $RAM_USED/$RAM_TOTAL ($RAM_PERC)
       Disk Usage      : $DISK_USED/$DISK_TOTAL ($DISK_PERC)
       CPU Load        : $CPU_LOAD
       Last Boot       : $LAST_BOOT
       LVM use         : $LVM
       TCP Connections : $TCP established
       Users logged    : $USER_LOG
       Network         : $IP_ADDR ($MAC_ADDR)
       Sudo            : $SUDO_LOG commands used
       ------------------------------------------------"
```
The wall command allows us to broadcast a message to all users in all terminals. This can be incorporated into the monitoring.sh script or added later in cron.\
Set permissions:
```
$ chmod 755 monitoring.sh
```
Enable cron:
```
$ systemctl enable cron
```
Show cron command line:
```
$ crontab -e
```
Add this line to crontab:
```
*/10 * * * * sh /root/monitoring.sh
```
Check crontab settings:
```
$ crontab -l
```
Stop cron without deleting script
```
$ systemctl stop cron.service
```
or
```
$ systemctl disable cron
```
# WordPress
To get the latest version of PHP needed to add a different APT repository, Sury's repository:
```
$ apt update
$ apt install curl
$ curl -sSL https://packages.sury.org/php/README.txt | bash -x
$ apt update
```
Install PHP version 8.1:
```
$ apt install php8.1
$ apt install php-common php-cgi php-cli php-mysql
```
Check php version:
```
$ php -v
```
Apache may be installed due to PHP dependencies. Uninstall it if it is to avoid conflicts with lighttpd:
```
$ systemctl status apache2
$ apt purge apache2
```
Install lighttpd:
```
$ apt install lighttpd
```
Chack version, start, enable lighttpd and check status:
```
$ lighttpd -v
$ systemctl start lighttpd
$ systemctl enable lighttpd
$ systemctl status lighttpd
```
Next, allow http port (port 80) through UFW:
```
$ ufw allow http
$ ufw status
```
And forward host port 8080 to guest port 80 in VirtualBox:
* Go to VM >> ```Settings``` >> ```Network``` >> ```Adapter 1``` >> ```Port Forwarding```
* Add rule for host port ```8080``` to forward to guest port ```80```

To test Lighttpd, go to host machine browser and type in address http://127.0.0.1:8080 or http://localhost:8080. You should see a Lighttpd "placeholder page".
Activate lighttpd FastCGI module:
```
$ lighty-enable-mod fastcgi
$ lighty-enable-mod fastcgi-php
$ service lighttpd force-reload
```
To test php is working with lighttpd, create a file in ```/var/www/html``` named ```info.php```:
```
<?php
phpinfo();
?>
```
Save and go to host browser and type in the address http://127.0.0.1:8080/info.php. You should get a page with PHP information.\
Install MariaDB:
```
$ apt install mariadb-server
```
Start, enable and check MariaDB status:
```
$ systemctl start mariadb
$ systemctl enable mariadb
$ systemctl status mariadb
```
Install MySQL secure:
```
$ mysql_secure_installation
```
Answer the questions like so (root here does not mean root user of VM, it's the root user of the databases):
```
Enter current password for root (enter for none): <Enter>
Switch to unix_socket authentication [Y/n]: Y
Set root password? [Y/n]: Y
New password: <your_password>
Re-enter new password: <your_password>
Remove anonymous users? [Y/n]: Y
Disallow root login remotely? [Y/n]: Y
Remove test database and access to it? [Y/n]:  Y
Reload privilege tables now? [Y/n]:  Y
```
Restart MariaDB service:
```
$ systemctl restart mariadb
```
Enter MariaDB interface:
```
$ mysql -u root -p
```
Enter MariaDB root password, then create a database for WordPress:
```
MariaDB [(none)]> CREATE DATABASE wordpress_db;
MariaDB [(none)]> CREATE USER 'admin'@'localhost' IDENTIFIED BY 'WPpassw0rd';
MariaDB [(none)]> GRANT ALL ON wordpress_db.* TO 'admin'@'localhost' IDENTIFIED BY 'WPpassw0rd' WITH GRANT OPTION;
MariaDB [(none)]> FLUSH PRIVILEGES;
MariaDB [(none)]> EXIT;
```
Check that the database was created successfully, go back into MariaDB interface:
```
$ mysql -u root -p
```
And show databases:
```
MariaDB [(none)]> show databases;
```
You should see something like this:
```
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| wordpress_db       |
+--------------------+
```
If the database is there, everything's good!
```
MariaDB [(none)]> EXIT;
```
Install two tools:
```
$ apt install wget
$ apt install tar
```
Download the latest version of Wordpress, extract it and place the contents in ```/var/www/html/``` directory. Then clean up archive and extraction directory:
```
$ wget http://wordpress.org/latest.tar.gz
$ tar -xzvf latest.tar.gz
$ mv wordpress/* /var/www/html/
$ rm -rf latest.tar.gz wordpress/
```
Create WordPress configuration file:
```
$ mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
```
Edit ```/var/www/html/wp-config.php``` with database info:
```
<?php
/* ... */
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_db' );

/** Database username */
define( 'DB_USER', 'admin' );

/** Database password */
define( 'DB_PASSWORD', 'WPpassw0rd' );

/** Database host */
define( 'DB_HOST', 'localhost' );
```
Change permissions of WordPress directory to grant rights to web server and restart lighttpd:
```
$ chown -R www-data:www-data /var/www/html/
$ chmod -R 755 /var/www/html/
$ systemctl restart lighttpd
```
In host browser, connect to http://127.0.0.1:8080 and finish WordPress installation.
# Fail2ban
Fail2ban scans log files (e.g. /var/log/apache/error_log) and bans IPs that show the malicious signs -- too many password failures, seeking for exploits, etc.\
Install Fail2ban:
```
$ apt install fail2ban
$ systemctl start fail2ban
$ systemctl enable fail2ban
$ systemctl status fail2ban
```
Create ```/etc/fail2ban/jail.local``` local cofiguration file:
```
$ cp /etc/fail2ban/jail.conf /etc/fail2ban/jail.local
```
Edit ```/etc/fail2ban/jail.local```, find line ~279 the ```#SSH servers``` heading and modify [sshd] configurations like this:
```
[sshd]

# To use more aggressive sshd modes set filter parameter "mode" in jail.local:
# normal (default), ddos, extra or aggressive (combines all).
# See "tests/files/logs/sshd" or "filter.d/sshd.conf" for usage example and details.
# mode   = normal
enabled  = true
maxretry = 3
findtime = 10m
bantime  = 1d
port     = 4242
logpath  = %(sshd_log)s
backend  = %(sshd_backend)s
```
Restart Fail2ban:
```
$ systemctl restart fail2ban
```
To check failed connection attempts and banned IP addresses, use these commands:
```
$ fail2ban-client status
$ fail2ban-client status sshd
```
Show last number of lines in fail2ban.log
```
$ tail -n <number_lines> /var/log/fail2ban.log
```
or
```
$ tail -f /var/log/fail2ban.log
```
Test by setting a low value bantime (like 10m) in ```/etc/fail2ban/jail.local``` sshd settings, and try to connect multiple times via SSH with the wrong password to get banned.
# Telnet
Install Telnet:
```
$ apt install telnet
```
# Train
https://itsfoss.com/ubuntu-terminal-train/ (It works only in akekesi, not in root)\
Install train:
```
apt install sl
```
Change the user’s parameters:\
```-a``` for accident mode. You can see people crying for help. Not for the faint-hearted)\
```-l``` for show a more miniature train but with more coaches\
```-F``` for a flying train like the Polar Express\
```-e``` for allow interrupt by Ctrl+C. In other modes, you cannot use Ctrl+C to stop the train. But then, it doesn’t run for long unless you have super ultra-wide monitor.
# Star Wars
Start:
```
$ telnet towel.blinkenlights.nl
```
Stop:
```
ctrl + ]
telnet > q
```
# FTP
not finished yet
# Snapshot
https://docs.oracle.com/en/virtualization/virtualbox/6.0/user/snapshots.html
# Signature
To extract the VM's signature, go to the Virtual Box VMs folder in your local computer (it could take a long time):
```
$ sha1sum <name_VM>.vdi
```
# Commands
Get date:
```
$ date "+%H:%M:%S   %d/%m/%y"
```
Check *sudo* installation:\
&rarr; list of installed debian packages pipe to look for sudo in it
```
$ dpkg -l | grep sudo
```
Show partitions:
```
$ lsblk
```
Check *sudo* privileges:
```
$ sudo whoami
root
```
Check *sudo* version:
```
$ sudo -V
```
Check SSH status:
```
$ systemctl status ssh
```
or
```
$ systemctl status ssh.service
```
or
```
$ service ssh status
```
Check UFW status:
```
$ ufw status
```
Reboot:
```
$ su -
$ reboot
```
IP with color:
```
$ ip -c a
```
Hostname:
```
$ hostname
$ hostname -i
$ hostname -I
```
Change hostname:
```
$ hostnamectl set-hostname <new_hostname>
$ hostnamectl status
```
Create new user:
```
$ adduser <username>
```
Change the user’s parameters:\
```-l``` for the username\
```-c``` for the full name\
```-g``` for groups by group ID
```
$ usermod <username>
```
Delete a user and all associated files:
```
$ deluser <username>
```
Show user ID:
```
$ id -u <username>
```
Show a list of all currently logged in users:
```
$ users
```
Show a list of all users on the machine:
```
$ cat /etc/passwd | cut -d ":" -f 1
```
Verify whether user was successfully created:
```
$ getent passwd <username>
```
Verify newly-created user's password expiry information:
```
$ chage -l <username>
```
Create new group:
```
$ addgroup <groupname>
```
Add user to group:
```
$ adduser <username> <groupname>
```
or
```
$ usermod -aG <groupname> <username>
```
Remove user from group:
```
$ gpasswd -d <username> <groupname>
```
Delete group:
```
$ delgroup <groupname>
```
Show groups of user:
```
$ groups
```
Show user's main group ID:
```
$ id -g
```
Show list of all users in group:
```
$ getent group <groupname>
```
Show fail2ban if it is installed for bonus
```
systemctl status fail2ban
```
Show last number of lines in fail2ban.log
```
$ tail -n <number_lines> /var/log/fail2ban.log
```
\
\
\
Check AppArmor status:
```
$ aa-status
```
Install telnet:
```
$ apt install telnet
```
