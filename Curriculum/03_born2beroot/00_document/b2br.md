# born2beroot
## Questions
* AppArmor status ???
* What is telnet ???

## Data
hostname: ```akekesi42```\
password: ```Password_b2br```

full name: ```attila kekesi```

usename: ```akekesi```\
password: ```Password_b2br```

encryption:\
password: ```Password_b2br```

## Links
[YouTube](https://www.youtube.com/watch?v=OQEdjt38ZJA) *(no audio)*\
[GitHub](https://github.com/ucefooo/born2beroot)\
[GitHub](https://github.com/mcombeau/Born2beroot)\
[Debian](https://www.debian.org)

## Table of Contents   
0. [Virtual Machine](#virtual-machine)
0. [*aptitude*](#aptitude)
0. [*sudo*](#sudo)
0. [SSH](#ssh)
0. [UFW](#ufw)
0. [Password Policy](#password-policy)
0. [AppArmor](#apparmor)
0. [Cron](#cron)
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
Select your VM >> Settings >> Network >> Adapter 1 >> Advanced >> Port Forwarding
- Add a rule with Host and Guest port 4242

Select your VM >> Settings >> Network >> Adapter 1
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
## !!! NOT FINIHED YET !!!
Show cron command line
```
$ crontab -e
```
Check Crontab settings:
```
$ crontab -l
```
Stop cron without deleting script
```
$ systemctl stop cron.service
```
# Commands
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
$ apt install telnet

Check AppArmor status:
```
$ aa-status
```