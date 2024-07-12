
# The Sort

## Overview
**The Sort** is a graphical simulation of various sorting algorithms implemented in C++ using the SFML library. It visually demonstrates how different sorting algorithms work.
This project is designed to help users understand the inner workings of these algorithms through interactive and visual representation.

## Features
- **Graphical Visualization:** Watch sorting algorithms in action with clear and colorful visualizations.
- **Multiple Algorithms:** Includes Bubble Sort, Insertion Sort, Selection Sort, Radix Sort, Merge Sort, and Quick Sort.
- **Interactive Controls:** Select, Generate, Shuffle and Start the simulation.
- **Step-by-Step Execution:** View the sorting process step-by-step for detailed understanding.

## Requirements
- C++ Compiler (g++ recommended)
- SFML Library

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/malayashekhar/TheSort.git
    cd TheSort
    ```

2. **Install SFML:**
    - **On macOS:**
        ```sh
        brew install sfml
        ```
    - **On Windows:**
        - Download the SFML library from the [official website](https://www.sfml-dev.org/download.php).
        - Follow the [tutorial](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) for setting up SFML with your compiler.

3. **Build the project:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

## Usage
1. **Run the executable:**
    ```sh
    ./TheSort
    ```

2. **Controls:**
    - `Enter`: Start the sorting process.
    - `1`: Select Bubble Sort.
    - `2`: Select Insertion Sort.
    - `3`: Select Selection Sort.
    - `4`: Select Radix Sort.
    - `5`: Select Merge Sort.
    - `6`: Select Quick Sort.
    - `S`: Shuffle.
    - `R`: Random generate.


## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
