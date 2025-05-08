# File Header

- **Programmer Name:** Lucas Dias
- **File Name:** `TheaterFinal` 
- **Summary:** The program simulates a movie theatre ticket system. It allows users to view seating charts, check seat prices, update prices, request tickets, and view a sales report. Seat prices are stored and loaded from an external file.
- **Program Purpose:** To manage theatre seating and ticket sales.
- **Most Challenging Aspect:**
  One of the challenging aspects was correctly implementing and consistently using pointer arithmetic for accessing and manipulating the 2D `seatingChart` array and 1D `seatPrices` array. Ensuring that all array accesses were correctly dereferencing pointers (e.g., `*(*(seatingChart + i) + j)` for 2D arrays, and `*(seatPrices + i)` for 1D arrays) required careful attention to detail to avoid errors and ensure memory safety. This was overcome by thoroughly understanding pointer operations in C++ and testing each array access method.
- **Time Spent on Project:** 3 days
- **Date Created:** 05/01/2025
- **Revision History:**
  - 05/01/2025: Initial program creation, core logic for seating, prices, and sales.
  - 05/08/2025: Updated menu display text for clarity ("Lucas's Super Theatre").

---

## Input/Output Data Chart

### Main Menu Interaction:
The program presents a numbered menu. The user inputs a number to select an option.

1.  **Display Seating Chart**
    *   **User Input:** Menu choice `1`.
    *   **Program Output:** Displays a grid of the theatre layout.
        *   `#` indicates an available seat.
        *   `*` indicates a taken seat.
        *   Row and seat numbers are displayed for reference.

2.  **Display Seating Prices**
    *   **User Input:** Menu choice `2`.
    *   **Program Output:** Lists the price for each row of seats (e.g., "Row 1: $10.00").

3.  **Update Seating Prices**
    *   **User Input:**
        *   Menu choice `3`.
        *   Row number to update (e.g., `1` to `15`), or `0` to finish updating.
        *   New price for the selected row (e.g., `12.50`).
    *   **Program Output:**
        *   Prompts for row number and new price.
        *   Confirmation message upon successful update.
        *   Updated prices are displayed.
        *   Prices are saved to `SeatPrices.txt`.

4.  **Request Tickets**
    *   **User Input:**
        *   Menu choice `4`.
        *   Number of tickets to purchase.
        *   For each ticket:
            *   Desired row number.
            *   Desired seat number in that row.
    *   **Program Output:**
        *   Prompts for the number of tickets, and then row/seat for each.
        *   Error message if a seat is already taken or invalid.
        *   Confirmation of successful purchase, including total cost for the transaction.
        *   The seating chart is updated to mark purchased seats with `*`.

5.  **Print Sales Report**
    *   **User Input:** Menu choice `5`.
    *   **Program Output:** A report including:
        *   Total number of seats sold.
        *   Total number of seats still available.
        *   Total ticket sales amount in dollars.

6.  **Exit**
    *   **User Input:** Menu choice `6`.
    *   **Program Output:** An exit message (e.g., "Exiting the program. Goodbye!").

### File I/O:

-   **Input File:** `SeatPrices.txt`
    *   **Content:** Contains one price per line, corresponding to each row in the theatre.
    *   **Usage:** Read at program startup to load seat prices. If the file is not found or is invalid, default prices are used, and a new `SeatPrices.txt` is created with these defaults.
-   **Output File:** `SeatPrices.txt`
    *   **Content:** Updated seat prices, one per line.
    *   **Usage:** Written to when seat prices are successfully updated by the user via menu option 3.

### Input Validation:
-   **User Input:** Menu choices, row numbers, seat numbers, prices.
-   **Program Output (on invalid input):**
    *   Error messages guiding the user (e.g., "Invalid choice. Please enter a number between 1 and 6.").
    *   Prompts to re-enter valid data.

---

## Function Documentation

### `main`
-   **Purpose:** Main entry point of the program. Initializes data structures (seating chart, prices), handles the main menu loop, and dispatches calls to other functions based on user input.
-   **Required Input:** None (implicitly, command line arguments if configured, but not used in this program).
-   **Provided Output:**
    *   Returns `0` to the operating system upon successful execution.
    *   All program interaction with the user (menus, prompts, results) originates from or is coordinated by `main`.

### `displayMenu`
-   **Purpose:** Displays the main menu options to the console, allowing the user to choose an action.
-   **Required Input:** None.
-   **Provided Output:** Prints the formatted menu text to the console.

### `initializeSeating`
-   **Purpose:** Sets all seats in the `seatingChart` array to an 'available' state (represented by `#`).
-   **Required Input:**
    *   `seatingChart`: A 2D `char` array (passed as `char (*)[COLS]`) representing the theatre seats.
-   **Provided Output:** The `seatingChart` array is modified in place; all elements are set to `#`.

### `loadPricesFromFile`
-   **Purpose:** Attempts to load seat prices for each row from the `SeatPrices.txt` file into the `seatPrices` array.
-   **Required Input:**
    *   `seatPrices`: A 1D `double` array (passed as `double*`) to store the loaded prices.
-   **Provided Output:**
    *   Returns `true` if prices are loaded successfully from the file.
    *   Returns `false` if the file doesn't exist or an error occurs during reading.
    *   The `seatPrices` array is populated with prices from the file or with default values if an error occurs during a specific read.
    *   Prints error messages to `std::cerr` if issues occur during reading individual prices.

### `savePricesToFile`
-   **Purpose:** Saves the current seat prices from the `seatPrices` array to the `SeatPrices.txt` file, overwriting it if it exists.
-   **Required Input:**
    *   `seatPrices`: A 1D `const double` array (passed as `const double*`) containing the prices to be saved.
-   **Provided Output:**
    *   Prints a confirmation message to the console upon successful save.
    *   Prints an error message to `std::cerr` if the file cannot be opened for writing.
    *   The `SeatPrices.txt` file is created or overwritten with the new prices.

### `createDefaultPriceFile`
-   **Purpose:** Populates the `seatPrices` array with predefined default prices and then calls `savePricesToFile` to write these defaults to `SeatPrices.txt`. This is typically used if the price file is not found at startup.
-   **Required Input:**
    *   `seatPrices`: A 1D `double` array (passed as `double*`) to be filled with default prices.
-   **Provided Output:**
    *   The `seatPrices` array is populated with default values.
    *   Calls `savePricesToFile`, which handles file output and console messages.

### `displaySeatingChart`
-   **Purpose:** Displays the current state of the `seatingChart` (available `#` and taken `*` seats) to the console in a formatted grid.
-   **Required Input:**
    *   `seatingChart`: A 2D `const char` array (passed as `const char (*)[COLS]`) representing the theatre seats.
-   **Provided Output:** Prints the formatted seating chart, including row and seat number guides, to the console. Also prints a legend for `#` and `*`.

### `displaySeatPrices`
-   **Purpose:** Displays the price for each row of seats to the console.
-   **Required Input:**
    *   `seatPrices`: A 1D `const double` array (passed as `const double*`) containing the prices for each row.
-   **Provided Output:** Prints a formatted list of seat prices (e.g., "Row X: $Y.YY") to the console.

### `updateSeatPrices`
-   **Purpose:** Allows the user to interactively update the price for a specific row. Changes are saved to `SeatPrices.txt`.
-   **Required Input:**
    *   `seatPrices`: A 1D `double` array (passed as `double*`) containing current seat prices. This array will be modified.
    *   **User Console Input:** Row number to update and the new price for that row.
-   **Provided Output:**
    *   The `seatPrices` array is modified with the new price for the selected row.
    *   Calls `savePricesToFile` to persist changes.
    *   Prints prompts for user input and confirmation/error messages to the console.

### `requestTickets`
-   **Purpose:** Manages the process of a user requesting and purchasing tickets. It updates the seating chart and accumulates total sales.
-   **Required Input:**
    *   `seatingChart`: A 2D `char` array (passed as `char (*)[COLS]`) to be updated when seats are sold.
    *   `seatPrices`: A 1D `const double` array (passed as `const double*`) used to calculate the cost of tickets.
    *   `totalSales`: A reference to a `double` (passed as `double&`) which accumulates the total revenue from all ticket sales.
    *   **User Console Input:** Number of tickets desired, and for each ticket, the row and seat number.
-   **Provided Output:**
    *   The `seatingChart` is modified: purchased seats are marked as `*`.
    *   The `totalSales` variable is updated with the value of the purchased tickets.
    *   Prints prompts for user input, the cost of the transaction, and confirmation/error messages to the console.

### `printSalesReport`
-   **Purpose:** Calculates and displays a sales report, including the number of seats sold, seats still available, and the total revenue generated.
-   **Required Input:**
    *   `seatingChart`: A 2D `const char` array (passed as `const char (*)[COLS]`) to count sold/available seats.
    *   `totalSales`: A `double` representing the total revenue from ticket sales.
-   **Provided Output:** Prints the sales report (number of seats sold, available, and total revenue) to the console.

### `getValidatedIntInput`
-   **Purpose:** Prompts the user for an integer input and validates it to be within a specified minimum (`minVal`) and maximum (`maxVal`) range. It handles non-numeric input and prompts for re-entry.
-   **Required Input:**
    *   `minVal`: The minimum acceptable integer value (inclusive).
    *   `maxVal`: The maximum acceptable integer value (inclusive).
    *   **User Console Input:** An integer value.
-   **Provided Output:**
    *   Returns the validated integer input from the user.
    *   Prints prompts for input and error messages for invalid input to the console.

### `getValidatedSeatInput`
-   **Purpose:** Prompts the user for an integer input specifically for seat or row numbers and validates it to be a positive integer up to `maxVal`. Handles non-numeric input and prompts for re-entry.
-   **Required Input:**
    *   `maxVal`: The maximum acceptable integer value (e.g., number of rows or columns).
    *   **User Console Input:** An integer value.
-   **Provided Output:**
    *   Returns the validated positive integer input from the user.
    *   Prints prompts for input and error messages for invalid input to the console.

---

## Code Sections (Commentary)

This section describes the purpose of major commented sections within the `TheaterFinal` source code. The line numbers refer to the original C++ source file.

-   **Section: Constants and Global Declarations (Lines 6-9)**
    *   **Purpose:** Defines constants for array dimensions (`ROWS`, `COLS`) and the filename for seat prices (`PRICE_FILENAME`). This centralizes configuration values, making them easy to find and modify if the theatre layout or price file name changes.

-   **Section: Function Prototypes (Lines 11-23)**
    *   **Purpose:** Declares all functions used in the program before their actual definitions. This allows functions to be called by `main` or other functions that appear earlier in the source file, adhering to C++'s requirement that functions must be declared before use.

-   **Section: `main` Function - Initialization (Lines 27-39)**
    *   **Purpose:** This part of `main` declares essential local variables: `seatingChart` (2D array for seats), `seatPrices` (1D array for prices per row), and `totalSales` (tracks revenue). It then calls `initializeSeating` to prepare the chart and `loadPricesFromFile` to fetch prices, creating a default price file via `createDefaultPriceFile` if `SeatPrices.txt` is missing.

-   **Section: `main` Function - Main Operation Loop (Lines 42-82)**
    *   **Purpose:** This `do-while` loop is the heart of the program's user interaction. It continuously:
        1.  Displays the main menu (`displayMenu`).
        2.  Gets validated user input for their choice (`getValidatedIntInput`).
        3.  Uses a `switch` statement to execute the corresponding functionality (e.g., `displaySeatingChart`, `requestTickets`).
        4.  The loop terminates when the user chooses to exit (option 6).
        5.  Includes logic to pause execution ("Press Enter to continue...") and clear the console screen (using `system("cls")` or `system("clear")`) for a cleaner user interface between menu displays.

-   **Section: `initializeSeating` Function - Nested Loops (Lines 103-107)**
    *   **Purpose:** Uses nested `for` loops to iterate through every seat in the `seatingChart`. Pointer arithmetic (`*(*(seatingChart + i) + j)`) is employed to access each seat element directly and initialize it to `#`, signifying it's available.

-   **Section: `loadPricesFromFile` Function - File Reading and Error Handling (Lines 111-127)**
    *   **Purpose:** Responsible for reading seat prices from `PRICE_FILENAME`. It opens an `std::ifstream`.
        *   If the file cannot be opened, it returns `false`.
        *   A `for` loop attempts to read one price per row. If a read operation fails (e.g., non-numeric data), it prints an error to `std::cerr`, sets a default price (0.0) for that row, clears stream error flags, and ignores the rest of the problematic line to attempt to continue reading subsequent rows.

-   **Section: `savePricesToFile` Function - File Writing (Lines 130-143)**
    *   **Purpose:** Writes the current seat prices to `PRICE_FILENAME`. It opens an `std::ofstream` (which overwrites the file if it exists or creates it if it doesn't). Prices are formatted to two decimal places. Pointer arithmetic (`*(seatPrices + i)`) is used to access prices.

-   **Section: `createDefaultPriceFile` Function - Default Data Initialization (Lines 146-158)**
    *   **Purpose:** Defines a hardcoded array of default prices. These are copied into the main `seatPrices` array using a `for` loop and pointer access. It then calls `savePricesToFile` to write these default prices to `SeatPrices.txt`.

-   **Section: `displaySeatingChart` Function - Chart Formatting (Lines 162-178)**
    *   **Purpose:** Generates a visual representation of the seating chart on the console. It prints column numbers as a header. Nested `for` loops iterate through rows and seats, printing the status of each seat (`#` or `*`). `std::setw` is used for aligning row numbers neatly.

-   **Section: `updateSeatPrices` Function - Interactive Price Update (Lines 191-216 in full source)**
    *   **Purpose:** Provides an interface for the user to change the price of seats in any given row. It first displays current prices. Then, in a loop (implicitly, allowing multiple updates until the user enters '0'), it prompts for a row number and a new price, validates these inputs, updates the `seatPrices` array, and calls `savePricesToFile` to persist the changes immediately.

-   **Section: `requestTickets` Function - Ticket Purchasing Logic (Lines 218-288 in full source)**
    *   **Purpose:** Handles the entire ticket purchasing flow. It asks the user how many tickets they want. Then, for each ticket:
        1.  Prompts for row and seat number.
        2.  Validates the input (within bounds, seat is available).
        3.  If valid, marks the seat as taken (`*`) in `seatingChart`.
        4.  Adds the price of that seat (from `seatPrices`) to a running total for the current transaction and to the global `totalSales`.
        5.  If invalid, an error message is shown, and the user might be re-prompted or the ticket sale for that specific seat fails.

-   **Section: `printSalesReport` Function - Report Calculation and Display (Lines 290-308 in full source)**
    *   **Purpose:** Compiles and displays key sales metrics. It iterates through the `seatingChart` using nested loops to count the number of sold seats (`*`) and available seats (`#`). It then prints these counts along with the `totalSales` revenue figure.

-   **Section: `getValidatedIntInput` / `getValidatedSeatInput` - Input Validation Loops (Lines 310-343 in full source)**
    *   **Purpose:** These are utility functions crucial for robust input handling. Each uses a `while` loop that continues to prompt the user until they enter a valid integer.
        *   They check if the input is of the correct type (integer).
        *   They check if the input falls within a specified range (`minVal` to `maxVal` for `getValidatedIntInput`, or `1` to `maxVal` for `getValidatedSeatInput`).
        *   If input is invalid (e.g., text instead of a number, or number out of range), `std::cin` error flags are cleared, the invalid input is discarded from the buffer, and an error message is displayed before re-prompting.
