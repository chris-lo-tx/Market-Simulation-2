# Market-Simulation-2
Project for programming fundamentals course. 


Part 0: Documenting the Code and Following Programming Standards

When developing code, it's crucial to document how the program works and adhere to programming standards. Add the program header below, replacing its information with details relevant to the program. Additionally, make sure that you follow the style guidelines for the course when developing the program. (Modules -> Module 0 -> C++ Programming Standards and Practices).

Part 1: Supermarket Information from a File 

Previously, the program had the user input the market name, the cost of the loyalty card fee of the market, and the total budget of the market. Since the program is being run more frequently, we need to replace the user input component with reading in the supermarket information from a file.  

First, the program should ask the user to enter a file to read. The program should keep prompting the user for a new filepath until a provided filepath exists OR they type "exit". If they type exit, the program should exit immediately with the message "Exiting simulation early".

Note: A valid filepath must have no spaces and contain the .txt extension. 

Code Block 8.2.1: File Prompt
Please enter filename: bad file.txt
Please enter a valid file path

Please enter filename: aaaa
Please enter a valid file path

Please enter filename: supermarket.txt
Processing supermarket.txt...
Once the user has entered a valid supermarket file, the program should open the file and process the information into a supermarket structure. Below is an example of what a supermarket file could contain.

Note: The comments will not be in the text file provided, there are just here to provide clarity. Additionally, you do not need to worry about the file missing information.

Code Block 8.2.2: supermarket.txt
CS Mart 2.0                // Name of the supermarket
8:00 am to 10:00 pm        // Supermarket hours
10.00                      // Membership fee (loyalty card cost)
10000.00                   // Supermarket starting budget
*Employee Information*     // Breaker line
15                         // Number of employees
14.27                      // Employee Salary
Part 2: Sentinel Controlled Loop

Now, we want to create an interactive menu kiosik for both customers and employees to use. First, we need to create a sentinel controlled loop which executes AT LEAST once and exits when the user provides a -1 input. Your loop should display the following menu each time the menu loop is executed.

Code Block 8.2.3: User Menu Display
Menu
=============================
1. Display Supermarket Information
2. Display Aisles information
3. Checkout
4. Access Employee Menu
-1. Exit program
=============================

Enter choice: 
Part 3: Creating User Menu Options

Now that we have created the menu loop, it's time to handle different user menu options. 

* Option 1: Display Supermarket Information - When the user enters 1, your program should display the supermarket information provided by the file. This supermarket information display should show the name of the supermarket, loyalty card cost, and starting budget. This display is similar to program 1.

* Option 2: Display Aisles information - When the user enters 2, your program should display the supermarket's aisle names from program 1.

* Option 3: Checkout -  When the user enters 3, the program should begin the checkout process.

First, the program should ask the user to enter their name. Once getting their name, the program should handle the follow two cases:

Supermarket Members: If the user exist in "members.txt", then the program should print "Welcome" followed by their name. Then, the program should continue the checkout process as if they were members. They should not be charged the membership fee again. 
Non Members: If the user does not exist in "members.txt", the program should ask them if they would like to become supermarket member. The program should accept both uppercase and lowercase 'y'. Every other input is treated as 'n'. 
If the user says yes, their name should be added to members.txt on a seperate line, the membership fee should be added to the cart total and the program should continue the checkout process as if they were members.
If the user says no, the program should use the regular item pricing.
Below is an example of what a members.txt file might look like.

Code Block 8.2.4: members.txt Example
Godzilla
Mickey Mouse
After determining their membership status, you need to ask what items they are buying. Follow the steps listed below:

Display current cart total
Ask for item name
Check if item exists
If item exists, ask how many they would like to buy
Calculate appropriate price based on membership status and add total to the cart
if item doe not exist, display "[Item name] is not sold at this store".
Repeat steps 1-3 until "End" is entered at step 2.
Display final total with tax added on.
Update total funds of the store based on the purchase.
DO NOT add the tax to the store funds.
Currently, these are the items your store has available for sale.

Item	
Wholesale Cost
Regular Price
Member Price
Frozen Pizza	
$3.75
$5.99
$5.49
Bag of Chips	
$1.85

$3.49
$2.99
Bleach	
$2.10
$3.79
$3.29
Shampoo	
$4.20
$6.99
$6.49
Ice Cream (1 pint)	
$2.95
$4.79
$4.29


Code Block 8.2.5: Checkout Examples
Menu
=============================
1. Display Supermarket Information
2. Display Aisles information
3. Checkout
4. Access Employee Menu
-1. Exit program
=============================

Enter choice: 3
What is your name? Sally
Would you like to become a loyalty member (y/n)? y

Current cart total: $10.00
Please enter item name (End to exit): chips
Please enter the amount you would like to purchase: 2

Current cart total: $15.98
Please enter item name (End to exit): oj
oj is not sold at this store

Current cart total: $15.98
Please enter item name (End to exit): End

Your total is $17.10

Menu
=============================
1. Display Supermarket Information
2. Display Aisles information
3. Checkout
4. Access Employee Menu
-1. Exit program
=============================

Enter choice: 3
What is your name? Sally
Welcome back Sally

Current cart total: $0.00
Please enter item name (End to exit): frozenPizza
Please enter the amount you would like to purchase: 1

Current cart total: $5.49
Please enter item name (End to exit): End

Your total is $5.87
Option 4: Access Employee Options - When the user enters 4, your program should prompt the user to input a store employee password. For this program, we can assume the default password is set to "csmart" when first starting the program. If the user enters the proper password, the user will be given access to an employee menu which we will create in parts 4 and 5 below. If the user enters the incorrect password, the program should display "Incorrect password." and display the menu again.

Additionally, if the user incorrectly enters the admin password more than 3 times, the program should exit with the message "Locking terminal. Please contact a store manager for assistance". The program should restart this counter every time the user successfully enters the employee password.

Code Block 8.2.6: Employee Access
Menu
=============================
1. Display Supermarket Information
2. Display Aisles information
3. Checkout
4. Access Employee Menu
-1. Exit program
=============================

Enter choice: 4
Enter employee password: badpass
Incorrect password.

Menu
=============================
1. Display Supermarket Information
2. Display Aisles information
3. Checkout
4. Access Employee Menu
-1. Exit program
=============================

Enter choice: 4
Enter employee password: csmart
Access granted

Employee Menu
Part 4: Creating Employee Menu

Create a sentinel controlled loop which executes AT LEAST once and exits when the user provides a -1 input. Your loop should display the following employee menu option each time the menu loop is executed. 

Part 5: Creating Employee Menu Options

Now that we have created our menu loop, it's time to handle the different admin menu options. 

* Option 1: Update Supermarket Information -  When the user enters 1, your program should prompt the user for a new supermarket file and update the supermarket information accordingly. However, if the file does not exist, your program should default back to the current supermarket file's information.

* Option 2: Pay Employees - When the user enters 2, your program should show how much paying the employees is going to cost, then update the total funds of the supermarket. If there are not enough funds, it should display "Not enough funds to pay employees".

* Option 3: Display Total Budget - When the user enters 3, your program should display the current budget/funds of the supermarket.

* Option 4: Clear Current Members - When the user enters 4, your program should reset the "members.txt" file.

* Option 4: Change Password - When the user enters 5, your program should prompt the user for a new employee password. Once given a new password, the employee password should be updated accordingly. Afterward, the user should be returned to the original menu. This means next time the user is prompted for the employee password, they will need to use the updated password.

Code Block 8.2.7: Employee Menu
Employee Menu
=============================
1. Update Supermarket File
2. Pay Employees
3. Display Total Funds
4. Clear Current Members
5. Change Password
-1. Exit Employee Menu
=============================

Enter choice: 
Program Requirements:

Your program MUST follow the C++ Standards Document provided on CANVAS.
Your program MUST compile for you to get credit.
Your program MUST close any files it opens.
Your program MUST NOT use any vectors. 
Your program should match the provided program output. 
Your program should use the appropriate datatypes for each variable. 
Any output which uses money should have a $ and should be properly rounded to the nearest hundredth place (or cent).
Use the provided szBreakMessage variable to print out the stars shown in the program.
Program Tips:

This program has several components. Work on a single part at a time and fully test it before moving on to the next part. Since there is no penalty for submitting multiple times (only the last submission is graded), I recommend you submit the assignment each time you finish developing a part. That way, if you don't finish it all in time, you will still receive partial credit.
You do not have to develop these parts in the order listed on the assignment. If you get stuck on a part, it may be a good idea to skip it and move on to the next one.
Remember to clear the buffer when switching between cin and getline by using cin.ignore().
