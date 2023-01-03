keki@keki-VirtualBox:~/00_git/42berlin/Curriculum/01_ft_printf/01_code$ paco -m -in
╔══════════════════════════════════════════════════════════════════════════════╗
║                Welcome to Francinette, a 42 tester framework!                ║
╚═══════════════════════╦══════════════════════════════╦═══════════════════════╝
                        ║            printf            ║
                        ╚══════════════════════════════╝
✔ Preparing framework
✔ Executing: make fclean bonus
ℹ Running tests: printfTester (https://github.com/Tripouille/printfTester)
[Mandatory]
category: c
// 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 
category: s
// 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 
category: p
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 
category: d
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 
category: i
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 
category: u
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 
category: x
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 30.KO 31.KO 
category: X
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 30.KO 31.KO 
category: %
// 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 
category: mix
1.KO 

Errors found:
For /home/keki/francinette/tests/printf/printfTester/tests/p_test.cpp:
25:     TEST(1, print(" %p ", -1));
26:     TEST(2, print(" %p ", 1));
27:     TEST(3, print(" %p ", 15));
28:     TEST(4, print(" %p ", 16));
29:     TEST(5, print(" %p ", 17));
30:     TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
31:     TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
32:     TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
33:     TEST(9, print(" %p %p ", 0, 0));

For /home/keki/francinette/tests/printf/printfTester/tests/d_test.cpp:
25:     TEST(1, print(" %d ", 0));
26:     TEST(2, print(" %d ", -1));
27:     TEST(3, print(" %d ", 1));
28:     TEST(4, print(" %d ", 9));
29:     TEST(5, print(" %d ", 10));
30:     TEST(6, print(" %d ", 11));
31:     TEST(7, print(" %d ", 15));
32:     TEST(8, print(" %d ", 16));
...

File too large. To see full report open: /home/keki/francinette/temp/printf/printfTester/errors.log

ℹ Running tests: fsoares (my own tests)
Want some more thorough tests? run 'francinette --strict'.

Summary: 

Failed tests: printfTester
keki@keki-VirtualBox:~/00_git/42berlin/Curriculum/01_ft_printf/01_code$ paco -b -in
╔══════════════════════════════════════════════════════════════════════════════╗
║                Welcome to Francinette, a 42 tester framework!                ║
╚═══════════════════════╦══════════════════════════════╦═══════════════════════╝
                        ║            printf            ║
                        ╚══════════════════════════════╝
✔ Preparing framework
✔ Executing: make fclean bonus
[Bonus]
category: -
subcategory: c
// 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 
subcategory: s
// 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 18.OK 19.OK 
subcategory: p
20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 
subcategory: d
30.KO 31.KO 32.KO 33.KO 34.KO 35.KO 36.KO 37.KO 38.KO 39.KO 40.KO 41.KO 42.KO 43.KO 44.KO 45.KO 46.KO 47.KO 48.KO 49.KO 50.KO 51.KO 52.KO 53.KO 54.KO 55.KO 56.KO 57.KO 58.KO 
subcategory: i
59.KO 60.KO 61.KO 62.KO 63.KO 64.KO 65.KO 66.KO 67.KO 68.KO 69.KO 70.KO 71.KO 72.KO 73.KO 74.KO 75.KO 76.KO 77.KO 78.KO 79.KO 80.KO 81.KO 82.KO 83.KO 84.KO 85.KO 86.KO 87.KO 
subcategory: u
88.KO 89.KO 90.KO 91.KO 92.KO 93.KO 94.KO 95.KO 96.KO 97.KO 98.KO 99.KO 100.KO 101.KO 102.KO 103.KO 104.KO 105.KO 106.KO 107.KO 108.KO 109.KO 110.KO 111.KO 112.KO 113.KO 114.KO 115.KO 116.KO 
subcategory: x
117.KO 118.KO 119.KO 120.KO 121.KO 122.KO 123.KO 124.KO 125.KO 126.KO 127.KO 128.KO 129.KO 130.KO 131.KO 132.KO 133.KO 134.KO 135.KO 136.KO 137.KO 138.KO 139.KO 140.KO 141.KO 142.KO 143.KO 144.KO 145.KO 
subcategory: X
146.KO 147.KO 148.KO 149.KO 150.KO 151.KO 152.KO 153.KO 154.KO 155.KO 156.KO 157.KO 158.KO 159.KO 160.KO 161.KO 162.KO 163.KO 164.KO 165.KO 166.KO 167.KO 168.KO 169.KO 170.KO 171.KO 172.KO 173.KO 174.KO 
category: 0
subcategory: d
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 
subcategory: i
29.KO 30.KO 31.KO 32.KO 33.KO 34.KO 35.KO 36.KO 37.KO 38.KO 39.KO 40.KO 41.KO 42.KO 43.KO 44.KO 45.KO 46.KO 47.KO 48.KO 49.KO 50.KO 51.KO 52.KO 53.KO 54.KO 55.KO 56.KO 57.KO 
subcategory: u
58.KO 59.KO 60.KO 61.KO 62.KO 63.KO 64.KO 65.KO 66.KO 67.KO 68.KO 69.KO 70.KO 71.KO 72.KO 73.KO 74.KO 75.KO 76.KO 77.KO 78.KO 79.KO 80.KO 81.KO 82.KO 83.KO 84.KO 85.KO 86.KO 
subcategory: x
87.KO 88.KO 89.KO 90.KO 91.KO 92.KO 93.KO 94.KO 95.KO 96.KO 97.KO 98.KO 99.KO 100.KO 101.KO 102.KO 103.KO 104.KO 105.KO 106.KO 107.KO 108.KO 109.KO 110.KO 111.KO 112.KO 113.KO 114.KO 115.KO 
subcategory: X
116.KO 117.KO 118.KO 119.KO 120.KO 121.KO 122.KO 123.KO 124.KO 125.KO 126.KO 127.KO 128.KO 129.KO 130.KO 131.KO 132.KO 133.KO 134.KO 135.KO 136.KO 137.KO 138.KO 139.KO 140.KO 141.KO 142.KO 143.KO 144.KO 
category: .
subcategory: s
1.OK 2.KO 3.KO 4.OK 5.KO 6.KO 7.KO 8.KO 9.KO 
subcategory: d
10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 30.KO 31.KO 32.KO 33.KO 34.KO 35.KO 36.KO 37.KO 38.KO 
subcategory: i
39.KO 40.KO 41.KO 42.KO 43.KO 44.KO 45.KO 46.KO 47.KO 48.KO 49.KO 50.KO 51.KO 52.KO 53.KO 54.KO 55.KO 56.KO 57.KO 58.KO 59.KO 60.KO 61.KO 62.KO 63.KO 64.KO 65.KO 66.KO 67.KO 
subcategory: u
68.KO 69.KO 70.KO 71.KO 72.KO 73.KO 74.KO 75.KO 76.KO 77.KO 78.KO 79.KO 80.KO 81.KO 82.KO 83.KO 84.KO 85.KO 86.KO 87.KO 88.KO 89.KO 90.KO 91.KO 92.KO 93.KO 94.KO 95.KO 96.KO 
subcategory: x
97.KO 98.KO 99.KO 100.KO 101.KO 102.KO 103.KO 104.KO 105.KO 106.KO 107.KO 108.KO 109.KO 110.KO 111.KO 112.KO 113.KO 114.KO 115.KO 116.KO 117.KO 118.KO 119.KO 120.KO 121.KO 122.KO 123.KO 124.KO 125.KO 
subcategory: X
126.KO 127.KO 128.KO 129.KO 130.KO 131.KO 132.KO 133.KO 134.KO 135.KO 136.KO 137.KO 138.KO 139.KO 140.KO 141.KO 142.KO 143.KO 144.KO 145.KO 146.KO 147.KO 148.KO 149.KO 150.KO 151.KO 152.KO 153.KO 154.KO 
category: #
subcategory: x
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 30.KO 
subcategory: X
31.KO 32.KO 33.KO 34.KO 35.KO 36.KO 37.KO 38.KO 39.KO 40.KO 41.KO 42.KO 43.KO 44.KO 45.KO 46.KO 47.KO 48.KO 49.KO 50.KO 51.KO 52.KO 53.KO 54.KO 55.KO 56.KO 57.KO 58.KO 59.KO 
category: ' '
subcategory: s
// 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 
subcategory: d
10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 29.KO 30.KO 31.KO 32.KO 33.KO 34.KO 35.KO 36.KO 37.KO 38.KO 
subcategory: i
39.KO 40.KO 41.KO 42.KO 43.KO 44.KO 45.KO 46.KO 47.KO 48.KO 49.KO 50.KO 51.KO 52.KO 53.KO 54.KO 55.KO 56.KO 57.KO 58.KO 59.KO 60.KO 61.KO 62.KO 63.KO 64.KO 65.KO 66.KO 67.KO 
category: +
subcategory: d
1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 25.KO 26.KO 27.KO 28.KO 
subcategory: i
29.KO 30.KO 31.KO 32.KO 33.KO 34.KO 35.KO 36.KO 37.KO 38.KO 39.KO 40.KO 41.KO 42.KO 43.KO 44.KO 45.KO 46.KO 47.KO 48.KO 49.KO 50.KO 51.KO 52.KO 53.KO 54.KO 55.KO 56.KO 57.KO 
