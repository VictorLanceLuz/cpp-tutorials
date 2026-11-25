
### Digital Art Gallery

In this project, you’ll create a simple Digital Art Gallery using C++. It will help manage different types of artworks such as paintings, sculptures, and digital pieces, while introducing key C++ concepts like constructors through the process of designing and handling art objects.

You will:

* Create an `Artwork` class to represent each piece of art. This class will store details such as the title, artist’s name, medium, price, and a unique ID.
* Write your own constructor to make sure every artwork object is created with the right information. You will also prevent creating incomplete objects by deleting the default constructor.
* Implement special functions like copy and move constructors, assignment operators, and a destructor. These functions help your program handle deep copies and resource management correctly.
* Build a `Gallery` class to store multiple artworks and allow adding them through copying or moving, depending on the situation.
* Add features like exhibitions and sales. You will create an `Exhibition` class to showcase selected artworks and mark them as sold when needed.
* Practice writing clean and safe C++ code using const correctness and encapsulation to protect your data.
* By the end of this project, you will have a working digital art gallery program that helps you apply core object-oriented programming concepts and understand how constructors work in C++.

A code review will be available once you finish the project.

1. To make sure every artwork in our gallery has meaningful data, we want to avoid allowing the creation of empty or uninitialized artwork objects.

In `Artwork.hpp`, delete the default constructor in the class `Artwork` to prevent creating objects that are missing important details like `title`, `artist`, or `price`.

2. To ensure that every artwork is created with all its essential details, we’ll require a constructor.

In `Artwork.hpp`, declare an explicit constructor inside the `Artwork` class that takes the following parameters:

- `artTitle` (`std::string`)
- `artistFullName` (`std::string`)
- `artworkId` (`int`)
- `artworkMedium` (`std::string`)
- `artworkPrice` (`double`)
- `soldStatus` (`bool`, defaults to `false`)

3. In `Artwork.cpp`, define the constructor you declared in the header file.

Inside the constructor, assign each parameter to its corresponding member variable: `title`, `artistName`, `id`, `medium`, `price`, and `sold` using the values passed to the constructor. Pass a default value `false` for `sold`.

4. In `main.cpp`:

- Create an `Artwork` object named `sunflowers` using the constructor you implemented.
- Pass the following values as arguments:
  - Title: `"Sunflowers"`
  - Artist name: `"Vincent van Gogh"`
  - ID: `1`
  - Medium: `"oil painting"`
  - Price: `1200000`

After creating the object, print its details in the following format to confirm that all values were set correctly:

```output
ID: <id>, Title: <title>, Artist: <artist>, Medium: <medium>, Price: <price>
```

## Adding Copy and Move Semantics in Artwork Class

5. Now, let’s say we want to create a copy of existing artwork for display in a different gallery.

To enable this, declare a copy constructor inside the `Artwork` class in `Artwork.hpp`. It should take a parameter named `other` of type `const Artwork&`.

This constructor performs a shallow copy, which is safe here since all members are value types or `std::string`, ensuring proper duplication without shared memory.

6. In `Artwork.cpp`, define the copy constructor using the parameter `const Artwork& other`, as declared in the header file.

Inside the constructor, use a member initializer list to copy `title`, `artistName`, `id`, `medium`, `price`, and `sold` directly from the original object.

7. In a digital art gallery, we might want to transfer artwork quickly, like moving it from a temporary collection to the main display. Instead of copying everything, we can use a move constructor to make this transfer more efficient.

In `Artwork.hpp`, inside the `Artwork` class, declare a move constructor that takes a parameter named `other` of type `Artwork&&`.

This constructor will be used when an `Artwork` object is initialized using an rvalue (temporary object).

8. In `Artwork.cpp`, define the move constructor with the parameter `Artwork&& other`.

Use a member initializer list to:

- Move `title`, `artistName`, and `medium` using `std::move`
- Copy `id`, `price` and `sold` directly

9. Let’s begin curating the gallery by creating an `Artwork` object named `starryNight` using the constructor with these values:

- `"Starry Night"` for the title
- `"Vincent van Gogh"` for the artist’s name
- `2` for the ID
- `"oil painting"` for the medium
- `1000000` for the price

10. Now, suppose we want to display the same artwork in another virtual exhibition. We can do this by creating a copy of the existing artwork.

In `main.cpp`, create an object named `galleryCopy` using the copy constructor and pass `starryNight` as the argument.

11. When transferring an artwork to another collection, like an auction system, we want to move the object rather than copy it for better performance.

Before moving an artwork to another collection, let’s mark it as ready for transfer.

In `main.cpp`, use `std::move()` on the existing artwork `starryNight` and assign the result to a temporary variable named `artworkForTransfer`.

12. Now that the artwork is ready to be transferred, let’s move it into a new object.

In `main.cpp`, create a new artwork object `auctionTransfer` using the move constructor. Pass `artworkForTransfer` as the argument to transfer its contents.

13. In `main.cpp`, print all three objects: `galleryCopy`, `auctionTransfer`, and `starryNight` to compare their values after copying and moving. Use the following format for each:

```output
ID: <id>, Title: <title>, Artist: <artistName>, Medium: <medium>, Price: <price> 
```

## Designing the Gallery to Manage Artworks

14. In `main.cpp`, create two more `Artwork` objects:

- The first object should be named `theScream` and created with the following values:

  - Title: `"The Scream"`
  - Artist: `"Edvard Munch"`
  - ID: `3`
  - Medium: `"tempera"`
  - Price: `1500000`
- The second object should be named `digitalDream` and created with:

  - Title: `"Digital Dream"`
  - Artist: `"Alice Doe"`
  - ID: `4`
  - Medium: `"digital art"`
  - Price: `5000`

15. Now that we’ve created individual artworks, let’s place them in our gallery where they can be displayed together.

In `main.cpp`, create a `Gallery` object named `gallery` to store the artwork collection.

Add the `sunflowers`, `theScream`, and `digitalDream` objects to the `gallery` by calling the `addArtwork()` method.

This ensures the original artwork objects are moved into the `artworks` vector, avoiding unnecessary copying.

16. In `main.cpp`, display the contents of the gallery by calling the `displayGallery()` to print all artworks currently stored and confirm that titles, artist names, media, and prices are shown correctly.
17. In real-world scenarios, galleries are unique and should not be copied wholesale. To reflect this behavior in our code, let’s explicitly disallow copying of the gallery.

In `Gallery.hpp`, delete the copy constructor for the class to prevent creating unintended copies of gallery objects.

## Curating an Exhibition and Managing Artwork Sales

18. Every exhibition begins as a blank canvas. Let’s define a default constructor to set the stage for adding artworks later.

Declare a default constructor for the class that initializes an exhibition without any featured artworks.

19. In the real world, exhibitions are often unique and shouldn’t be duplicated casually. To prevent this, let’s explicitly delete the copy constructor.

In Exhibition.hpp, inside the `Exhibition` class, delete the copy constructor.

20. Let’s test how the system behaves when artworks are sold and check if the exhibition reflects those changes correctly.

In `main.cpp`:

- Create an `Exhibition` object named `exhibition`.
- Add the first and the third artworks (index `0` and `2`) to the exhibition using `addToExhibition()`.
- Display the exhibition before selling any artworks by calling `showExhibition()`.
- Mark the artwork with ID 4 as sold using `sellArtwork()`.
- Display the exhibition again by calling `showExhibition()` to confirm that the sale status has been updated.

## Wrapping Up & Next Steps

21. Great job reaching the end of this project!

Now that you have a solid foundation, here are some ideas to deepen your understanding of constructors:

- In the `Artwork` class, make the default constructor delegate to the main constructor by passing default values: `"Untitled"` for title, `"Unknown"` for artistName, `-1` for id, `"N/A"` for medium, and `0.0` for price.
- If all exhibitions must have a name or featured artworks, delete the default constructor for `Exhibition` class and require initialization with data.

Keep exploring constructor techniques to deepen your understanding of object-oriented design and write more robust, efficient code!
