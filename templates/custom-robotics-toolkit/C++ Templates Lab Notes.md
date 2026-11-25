# Custom Robotics Toolkit with Templates

You’ve been hired to create a “Custom Toolkit” for a robotics lab! This toolkit will handle data of different types (like integers, doubles, and strings) without needing repetitive code. To accomplish this, you’ll use **C++ templates** to make functions and classes more flexible and reusable.

You’ll start by crafting function templates to compare and manipulate data, followed by designing a generic class to store and retrieve values of any type. Along the way, you’ll customize your templates to handle special cases (like strings) and even create a function that can process multiple inputs at once. By the end, you’ll combine all these tools into a cohesive demo, showcasing the power and simplicity of templates in action. Get ready to build something awesome!

## Create Flexible Functions

1. The robotics lab wants a reusable function to find the midpoint between two values (e.g., integers, doubles, or floats). Let’s create a **function template** to solve this!

   In`functions.hpp`, create a function template called midpoint() that takes two parameters (a and b) of the same type and returns the midpoint between them.

   Use this formula for finding the midpoint:

   $$
   m = a + \frac{b - a}{2}
   $$

   The variable`m` is the midpoint between a (smaller number) and `b` (larger number).
2. Let’s try the `midpoint(a, b)` function. In the `main()` function of `main.cpp`, call `midpoint(a, b)` with the values `10` and `20` and print the result. What is the midpoint?
3. Next, test `midpoint(a, b)` in `main.cpp` with the doubles `2.71` and `3.14` and print the result.
4. The lab now needs a function to swap the positions of two values. Let’s add a new function template for this.

   Back in functions.hpp, create a**function template** called `swapValues(a, b)` that swaps the positions of two values using a temporary variable.
5. Time to swap things around! In the `main()` function of `main.cpp`, create two integers called `firstNumber` and `secondNumber`. Set `firstNumber` to `5` and `secondNumber` to `10`.
6. Now, use `swapValues(a, b)` and print both `firstNumber `and `secondNumber `after the swap.
7. Finally, test `swapValues()` in `main.cpp` with two string variables: `greeting = "hello"` and `planet = "world"`. Swap them and print the new values.

## Build a DataHolder Class

8. The lab requires a generic object that can store and retrieve values of any type while ensuring that these values remain within specified bounds for safety reasons.

   For instance, if the lab is working on a four-wheeled robot and measuring its speed (to be stored in a generic data object), it is crucial to prevent the speed from exceeding a certain limit to avoid damaging the robot. To do this, we will build a class called `DataHolder`.

   To start, in `DataHolder.hpp`, create a class template called `DataHolder`.
9. Add the following private members to `DataHolder`:

   - A variable called `storedValue` of type `T`.
   - A variable of type `T` called `maxValue` to store the maximum possible value of `storedValue`.
   - A variable of type `T` called `minValue` to store the minimum possible value of `storedValue`.
10. For the `DataHolder` class, add a constructor that takes three parameters, `val`, `min`, and `max`. For now, use `min` and `max` to initialize `minValue` and `maxValue`.
11. Let’s set the value of `storedValue` if it is within the bounds of `min` and `max`.

    In the constructor, if `val` is within the bounds of `min` and `max`, set the value of `storedValue` to `val`.
12. Let’s continue working on the constructor.

    If `val` is higher than `max`, set `storedValue` to `max` and print a message which follows this format (be sure to fill in `val` and `max`):

    ```
	WARNING: val is too high! Setting value to max!Copy to Clipboard
    ```

13. If `val` is lower than `min`, set `storedValue` to `min` and print a message which follows this format (be sure to fill in `val` and `min`):

    ```
    WARNING: val is too low! Setting value to min!Copy to Clipboard
    ```

14. The lab now wants to be able to update the value stored in `DataHolder`. Let’s add a `setValue(newValue)` method.

    In the `DataHolder` class, add a public method called `setValue()` that takes one parameter of type `T` called `newValue` and updates the value of `storedValue` if it is within the bounds of `minValue` and `maxValue`.
15. Let’s handle cases where `newValue` is out of the bounds of `maxValue` and `minValue`.

    If `newValue` is greater than `maxValue`, set `storedValue` to `maxValue` and print a message following this format:

    ```
    WARNING: val is too high! Setting value to max!Copy to Clipboard
    ```

    If`newValue` is lower than `minValue`, set `storedValue` to `minValue` and print a message following this format:

    ```
    WARNING: val is too low! Setting value to min!Copy to Clipboard
    ```

16. Add a method called `getValue()` to `DataHolder` that returns the value of `storedValue`.

## Testing the DataHolder Class

17. Let’s give the `DataHolder` class a spin!

    In the`main()` function of `main.cpp`, create a `DataHolder` called `testNumber` for an integer with the value `42` and a minimum and maximum of `0` and `100`. Use `getValue()` to retrieve and print the value.

18. Try to set the value of `testNumber` to `75`.
19. Try to set the value of `testNumber` to `150`.

## Customizing DataHolder for Strings

20. Sometimes, the lab needs to handle certain types differently. For example, they want `DataHolder` to store strings. The current implementation of `DataHolder` requires a minimum and maximum value for a variable, which wouldn’t make sense if the type was a string. We can use **template specialization** to create a custom `DataHolder` class just for strings!

    In`DataHolder.hpp`, start by writing a specialization of the `DataHolder` class that is a copy of the original `DataHolder` class but with `minValue` and `maxValue` removed.

21. Create a constructor for this `DataHolder` class that accepts a parameter called `val`, and uses it to initialize `storedValue`.
22. Create a setter function called `setValue(newString)` that sets the value of `storedValue` to `newString`.
23. Create a getter function for this class called `getValue()` that returns the value of `storedValue()`.
24. Let’s check how the specialized `DataHolder` for strings works. In the `main()` function of `main.cpp`, create a `DataHolder` object for a string called `testString` with the value `"robotics lab"`. Use `getValue()` to print the value of `testString` to ensure that everything is correct.

## Bring It All Together

25. Now that you’ve built the individual tools, let’s combine them into one cohesive toolkit! Start by creating a function called `runToolkitDemo()` that returns `void` in `main.cpp` (make sure to put this function above `main()`). Inside this function, call `midpoint(100, 200)` and print the result.

26. In `runToolkitDemo()`, declare two string variables called `part1` and `part2`, initialized with `"chassis"` and `"engine"`, respectively. Call `swapValues()` on the two strings and print the swapped values.

27. Still in `runToolkitDemo()`, create a `DataHolder` object called `specialNumber` with an initial value of `2.71`, a minimum of `1.618`, and a maximum of `9.8`. Print `specialNumber`.

28. Create a specialized `DataHolder` object called `robotName` for a string with the value `"Codey the Robot"`. Print its value.

29. Now for the big finale! In your `main()` function, call `runToolkitDemo()` to show off everything you’ve built. Watch as your flexible and powerful toolkit does its thing!

30. Congratulations on completing the project!

    You’ve built a flexible and powerful toolkit using **templates** in C++. From generic functions and reusable classes to template specialization, we’ve covered a lot of ground. These tools are just the beginning — templates allow us to write cleaner, more efficient code for almost any type of data. Great job!