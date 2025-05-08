# Theater System Doc

- **Programmer Name:** Lucas Dias
- **File Name:** `TheaterFinal` 
- **Summary:** The program simulates a movie theatre ticket system. It allows users to view seating charts, check seat prices, update prices, request tickets, and view a sales report. Seat prices are stored and loaded from an external file. There's an excessive amount of pointers used, and it's pretty much there for the extra points. Normally, I'd use them, but not to this extent. 
- **Program Purpose:** To manage theatre seating and ticket sales.
- **Most Challenging Aspect:**
  One of the challenging aspects was correctly implementing and consistently using pointers for accessing and changing the 2D `seatingChart` array and the `seatPrices` array. Ensuring that all array accesses were correctly dereferencing pointers (e.g., `*(*(seatingChart + i) + j)` for 2D arrays, and `*(seatPrices + i)` for 1D arrays) required a lot of debugging to avoid errors. This was overcome by thoroughly understanding pointer operations in C++ and testing each  access method.
- **Time Spent on Project:** Around a week, wasn't too hard as I did it before but I spaced the time spent on it a lot.
- **Date Created:** 05/01/2025
- **Revision History:**
  - 05/01/2025: Initial program creation, set up logic for seating, prices, and sales. Started documentation, made it work with GitHub w/ an old format I had.
  - 05/04/2025: Added functions for seat prices and sales.
  - 05/05/2025: Added functions for seating chart and ticket requests.
  - 05/06/2025: Added functions for file operations.
  - 05/08/2025: Final update to documentation.

---

## Inputs and Outputs

### Main Menu Interaction:
The program displays a menu with numbered options. The user enters a number to select an action.

1.  **Display Seating Chart**
    *   **User Input:** Menu option `1`.
    *   **Program Output:** Displays a grid representing the theatre seats.
        *   `#` indicates an available seat.
        *   `*` indicates a taken seat.
        *   Row and seat numbers are shown for reference.

2.  **Display Seating Prices**
    *   **User Input:** Menu option `2`.
    *   **Program Output:** Lists the price for each row.

3.  **Update Seating Prices**
    *   **User Input:**
        *   Menu option `3`.
        *   The row number to update (1-15), I used `0` to finish updating.
        *   The new price for the selected row.
    *   **Program Output:**
        *   Prompts for the row number and the new price.
        *   Confirmation message if the update is successful.
        *   Displays an updated list of prices.
        *   Saves the new prices to the `SeatPrices.txt` file.

4.  **Request Tickets**
    *   **User Input:**
        *   Menu option `4`.
        *   The number of tickets to purchase.
        *   For each ticket: the desired row number and seat number.
    *   **Program Output:**
        *   Prompts for the number of tickets, then for the row and seat for each.
        *   An error message if a selected seat is already taken or the input is invalid.
        *   Confirmation of a successful purchase, including the total cost.
        *   The seating chart is updated, marking purchased seats with `*`.

5.  **Print Sales Report**
    *   **User Input:** Menu option `5`.
    *   **Program Output:** A sales report showing:
        *   Total number of seats sold.
        *   Total number of seats still available.
        *   Profit from ticket sales.

6.  **Exit**
    *   **User Input:** Menu option `6`.
    *   **Program Output:** Exit message.

### File Operations:

-   **Input File:** `SeatPrices.txt`
    *   **Contents:** Stores one price per line, corresponding to each row in the theatre.
    *   **How it's used:** The program reads this file at startup to load the seat prices. If the file isn't found or is corrupted, it uses a set of default prices and creates a new `SeatPrices.txt` file with these defaults.
-   **Output File:** `SeatPrices.txt`
    *   **Contents:** Stores the updated seat prices, one price per line.
    *   **How it's used:** When the user updates seat prices through option 3, the program writes the new prices to this file.

---

## Function Descriptions

### `main`
-   **Purpose:** The starting point of the program (duh). It sets up the data, manages the main menu loop, and calls other functions based on what the user selects.
-   **Input:** None.
-   **Output:** Returns `0` to the operating system if the program finishes correctly. Handles all interactions with the user.

### `displayMenu`
-   **Purpose:** Shows the main menu options on the screen.
-   **Input:** None.
-   **Output:** Prints the menu to the console.

### `initializeSeating`
-   **Purpose:** Prepares the seating chart by marking all seats as available using the `#` character.
-   **Input:**
    *   `seatingChart`: The 2D array grid that holds the status of all seats.
-   **Output:** Modifies the `seatingChart` array directly – all seats are set to `#`.

### `loadPricesFromFile`
-   **Purpose:** Tries to read the seat prices for each row from the `SeatPrices.txt` file and stores them.
-   **Input:**
    *   `seatPrices`: An array where the prices will be stored.
-   **Output:**
    *   Returns `true` if prices are loaded correctly.
    *   Returns `false` if the file is missing or there's an error reading it.
    *   The `seatPrices` array is filled with prices from the file. If a specific price can't be read, a default value (0.0) is used for that row, and an error message is shown.

### `savePricesToFile`
-   **Purpose:** Writes the current seat prices from the `seatPrices` array into the `SeatPrices.txt` file. If the file exists, it's overwritten.
-   **Input:**
    *   `seatPrices`: The array containing the current prices to be saved.
-   **Output:**
    *   Prints a confirmation message to the console if saving is successful (blessed for debugging).
    *   Prints an error message if the file cannot be opened for writing.
    *   The `SeatPrices.txt` file is created or updated with the new prices.

### `createDefaultPriceFile`
-   **Purpose:** Fills the `seatPrices` array with a set of default prices. Then it calls `savePricesToFile` to write these defaults on `SeatPrices.txt`. This is used if the price file isn't found when the program starts.
-   **Input:**
    *   `seatPrices`: The array that will be filled with the default prices.
-   **Output:**
    *   The `seatPrices` array with default values.
    *   `savePricesToFile` is called, which handles writing to the file and the console messages.

### `displaySeatingChart`
-   **Purpose:** Shows the current seating chart, indicating available (`#`) and taken (`*`) seats in a grid format.
-   **Input:**
    *   `seatingChart`: The 2D array grid holding the status of all the theatre seats.
-   **Output:** Prints the seating chart, including row/seat numbers and a legend for `#` and `*`.

### `displaySeatPrices`
-   **Purpose:** Shows the price for each row of seats.
-   **Input:**
    *   `seatPrices`: The array containing the price for each row.
-   **Output:** Prints a formatted list of seat prices.

### `updateSeatPrices`
-   **Purpose:** Allows the user to change the price for a specific row. The changes are then saved to `SeatPrices.txt`.
-   **Input:**
    *   `seatPrices`: The array of current seat prices; this array will be updated.
    *   **User Input:** The row number to change and the new price.
-   **Output:**
    *   The `seatPrices` array is updated with the new price.
    *   `savePricesToFile` is called to save the changes.
    *   Prints messages for user prompts and confirmations.

### `requestTickets`
-   **Purpose:** Manages the ticket purchasing process. It updates the seating chart to mark seats as sold and keeps track of total sales revenue.
-   **Input:**
    *   `seatingChart`: The 2D array grid for seats, which is updated when seats are sold.
    *   `seatPrices`: The array of prices, used to calculate ticket costs.
    *   `totalSales`: A variable that accumulates the total money from all ticket sales; this variable is updated.
    *   **User Input:** The number of tickets desired, and the row/seat number for each ticket.
-   **Output:**
    *   The `seatingChart` is updated: purchased seats are marked `*`.
    *   The `totalSales` variable is increased by the cost of the purchased tickets.
    *   Prints console messages for user prompts, transaction costs, and confirmations/errors.

### `printSalesReport`
-   **Purpose:** Calculates and displays a sales report, including how many seats were sold, how many are still available, and the total revenue.
-   **Input:**
    *   `seatingChart`: The 2D array grid of seats, used to count sold vs. available.
    *   `totalSales`: The variable holding the total revenue from all ticket sales.
-   **Output:** Sales report (number of seats sold, available, and total money made).

### `getValidatedIntInput`
-   **Purpose:** Asks the user for an integer and makes sure it's within a specified range. If the input is not a valid number or out of range, it prompts the user to try again.
-   **Input:**
    *   `minVal`: The smallest acceptable integer.
    *   `maxVal`: The largest acceptable integer.
    *   **User Input:** An integer.
-   **Output:**
    *   Returns the integer entered by the user.
    *   Prints messages for prompts and errors.

### `getValidatedSeatInput`
-   **Purpose:** Asks the user for an integer for a seat or row number. Make sure the input is a positive number and not greater than a specified maximum. Prompt for re-entry if the input is invalid.
-   **Input:**
    *   `maxVal`: The highest acceptable number (total rows).
    *   **User Input:** An integer.
-   **Output:**
    *   Returns the positive integer entered by the user.
    *   Prints messages for prompts and errors.

---

## Code Sections/Comments

-   **Lines 6-9**
    *   **Explanation:** This area defines fixed values used throughout the program. `ROWS` and `COLS` set the size of the theatre. `PRICE_FILENAME` says the name of the file (`SeatPrices.txt`) where prices are stored. Using constants makes it easier to update these values when needed.

-   **Prototypes (Lines 11-23)**
    *   **Explanation:** These lines list all the functions defined in the program. In C++, a function must be declared before it's used. Prototypes would tell the compiler the function's name, what kind of data it expects as input, and what kind of data it will return. This allows `main` (or other functions) to call functions that are defined later.

-   **Variable Declarations (Lines 27-39)**
    *   **Explanation:** At the start of `main`, variables are created: `seatingChart`, `seatPrices`, and `totalSales`. The program then calls `initializeSeating` to set up the empty seating chart and `loadPricesFromFile` to get prices from the file, or `createDefaultPriceFile` if `SeatPrices.txt` doesn't exist.

-   **Main Operation Loop (Lines 42-82)**
    *   **Explanation:** This `do-while` loop is the main interaction loop. It repeatedly:
        1.  Calls `displayMenu` to show options.
        2.  Gets the user's choice using `getValidatedIntInput`.
        3.  A `switch` statement then runs the code corresponding to the user's choice.
        4.  The loop continues until the user selects option 6.
        5.  It includes code to pause and clear the screen.

-   **Using Nested Loops (Lines 103-107)**
    *   **Explanation:** Two `for` loops, one inside the other (nested), are used to go through each seat in the `seatingChart`. Pointer expressions like `*(*(seatingChart + i) + j)` are used to directly access and set each seat's value to `#`.

-   **File Reading with Error Checks (Lines 111-127)**
    *   **Explanation:** This function reads prices from `PRICE_FILENAME`. It tries to open the file. If it fails, it returns `false`. Otherwise, it loops through each row, trying to read a price. If a read fails for a specific row, it prints an error, uses a default price (0.0) for that row, and tries to continue with the next rows.

-   **Writing Data to File (Lines 130-143)**
    *   **Explanation:** This function writes the current seat prices to `PRICE_FILENAME`. It opens the file for writing (this will overwrite the file if it exists or create it if it doesn't). Prices are formatted to two decimal places. Pointer expressions like `*(seatPrices + i)` are used to access each price.

-   **Setting Default Values (Lines 146-158)**
    *   **Explanation:** This function contains a predefined list of default prices. These are copied into the main `seatPrices` array. Then, `savePricesToFile` is called to write these defaults into `SeatPrices.txt`.

-   **Formatting the Chart (Lines 162-178)**
    *   **Explanation:** This function creates the visual display of the seating chart. It prints column numbers at the top. Nested `for` loops go through each seat, printing its status (`#` or `*`). `std::setw` helps align row numbers neatly.

-   **Interactive Updates (Lines 191-216)**
    *   **Explanation:** This allows the user to change row prices. It shows current prices, then repeatedly asks for a row number and new price (until the user enters '0' for the row). Inputs are validated, the `seatPrices` array is updated, and `savePricesToFile` is called to make the changes permanent.

-   **Ticket Purchasing Steps (Lines 218-288)**
    *   **Explanation:** This manages ticket sales:
        1.  Asks for the number of tickets.
        2.  For each ticket, asks for row and seat, then validates the choice (is the seat real and available?).
        3.  If valid, marks the seat as taken (`*`) in `seatingChart`.
        4.  Adds the seat's price to the transaction total and to the overall `totalSales`.
        5.  If invalid, an error message is shown.

-   **Summarizing Sales (Lines 290-308)**
    *   **Explanation:** This function calculates and shows the sales data. It loops through `seatingChart` to count sold and available seats, then prints these counts along with the `totalSales` revenue.

-   **Ensuring Valid User Input (Lines 310-343)**
    *   **Explanation:** These functions make sure the user enters valid numbers. Each uses a `while` loop that keeps prompting until a correct integer is entered.
        *   They check if the input is actually an integer and if it's within the allowed range.
        *   If the input is bad, error flags in `std::cin` are cleared, the bad input is ignored, an error message is shown, and then the user is prompted again.