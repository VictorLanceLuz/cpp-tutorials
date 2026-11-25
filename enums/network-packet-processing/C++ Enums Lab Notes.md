### Network Packet Processing

In this project, you will develop a network packet processing system using C++. The goal is to create a system capable of handling various types of network packets, protocols, and status states. Throughout the project, you will implement packet validation, protocol handling, and status management while exploring best practices for using `enum` and type safety features.

What you will do:

* create enums for packet types
* set up the `Packet` class
* implement protocol handling
* manage packet status
* build validation logic
* ensure type safety

Let’s get started!

## Creating the Necessary Enums

**1.** To start building our network packet processing system, we will need enums to represent a packet type, protocol, and status. These types are crucial for processing packets correctly and efficiently.

To begin, in `PacketType.hpp`, create a traditional `enum` called `PacketType` that includes the following values:

* `UNKNOWN`
* `DATA`
* `CONTROL`
* `ERROR`

These values represent the various packet types that will be encountered in a network environment.

**2.** Our system must handle various network protocols such as TCP, UDP, HTTP, and FTP. We can represent these using an `enum class`.

To represent these protocols, in `Protocol.hpp` create an `enum class` named `Protocol` and include the following values:

* `TCP`
* `UDP`
* `HTTP`
* `FTP`

**3.** We need an enum to represent each packet’s status to effectively manage its state.

In `Status.hpp`, create an `enum class` called `Status` that represents the different states a packet can have during its lifecycle.

In `Status`, include the following values:

* `PENDING`
* `VALID`
* `INVALID`
* `TIMEOUT`

## Updating the Packet Class

**4.** There is a `Packet` class that we can use to represent a packet. Some members already exist. However, you will have to complete its construction.

To start, in `Packet.hpp`, add a private member called `type` that is a `PacketType` to store the packet’s type.

**5.** Add a public setter function called `setType(PacketType newType)` to modify the packet’s type from outside the class. Declare this in the header file (`Packet.hpp`) and implement it in the source file (`Packet.cpp`).

**6.** The `Packet` class must have a member to represent the protocol.

In the `Packet` class (`Packet.hpp`), add a private variable called `protocol` of type `Protocol`.

**7.** The `Packet` class must have a member to record the status of a packet. In the `Packet` class, create a private member called `packetStatus` of type `Status`.

**8.** Add a constructor to the `Packet` class to initialize the `type` and `protocol` members. Use `pType` and `prtcl` for the `type` and `Protocol` members, respectively.

## Implementing Packet Functions

**9.** Let’s start filling out the functions in our `Packet` class. We will start with the `getProtocolName()` function.

In the `Packet.cpp` file, create an empty switch statement that checks the `protocol` member in the `getProtocolName()` function.

**10.** Inside the switch statement, for each possible value of `Protocol`, write a case that returns the value as a string. For example, if the protocol is `TCP`, the function should return `"TCP"`. The protocols are:

* `TCP`
* `UDP`
* `HTTP`
* `FTP`

**11.** Create a default case to handle situations where `protocol` is not defined. In this case, return the string `"Unknown Protocol"`

**12.** Let’s continue by working on the `getPacketTypeName()` function.

To start, create an empty switch statement inside `getPacketTypeName()` to check the `type` variable.

**13.** In the `getPacketTypeName()` function, create cases to handle each `type`. The types are:

* `UNKNOWN`
* `DATA`
* `CONTROL`
* `ERROR`

For each case, return a string that is the `type` value. For example, for `UNKNOWN`, return `"UNKNOWN"`.

**14.** In the switch statement for `type`, add a default case that handles a `type` that is not a member of the `PacketType` enum. For this case, return the string `"UNKNOWN ERROR"`

**15.** Let’s work on the `getStatusName()` function.

In `getStatusName()`, create an empty switch statement that checks the `packetStatus` member.

**16.** In the switch statement for `packetStatus`, create a case to handle each of the possible `Status` values for `packetStatus`. In each case, return a string that is the `Status` value. For example, return `"PENDING"` for `PENDING`.

The possible `Status` values are:

* `PENDING`
* `VALID`
* `INVALID`
* `TIMEOUT`

**17.** Add a default case to handle a situation where a `packetStatus` is not a member of `Status`. In this case, return the string `"Unknown Packet Status"`.

**18.** Let’s start working on the `validatePacket()` function. To start, create a `switch` statement that checks the `type` variable. You can leave it empty for now.

**19.** In the `switch` statement, have the following happen when `type` (of type `PacketType`) is `DATA`:

* If the `protocol` (of type `Protocol`) is `TCP` or `UDP`, set `packetStatus` to a `Status` of `VALID`.
* Otherwise, set `packetStatus` to a `Status` of `INVALID`.

**20.** Write a case for when `type` is `CONTROL` so that the following will happen:

* Set `packetStatus` to a `Status` of `VALID` if the protocol is `TCP`.
* Otherwise, set `packetStatus` to `INVALID`.

**21.** `ERROR` packets are considered valid for all protocols. In the `validatePacket()` function, write a case for when `type` is `ERROR`. In this case, set `packetStatus` to a `Status` of `VALID`.

**22.** Write a case to handle the `type` of `UNKNOWN`. In this case, set `packetStatus` to `Status` of `INVALID`.

**23.** Also, create a default case to handle potential packets that do not exist in the `PacketType` enum. In this case, set `packetStatus` to a `Status` of `INVALID`.

**24.** In your network packet processing system, you might need to determine if a `Packet` is invalid for logging or error handling purposes. We will implement this functionality in the `isError()` function.

In the function, return `true` if the `packetStatus` member is set to a `Status` value of `INVALID`. Return `false` otherwise.

**25.** In the `displayInfo()` function, use `getPacketTypeName()`, `getProtocolName()`, and `getStatusName()` to print the packet’s type, protocol, and status, respectively.

## Testing and Validation

**26.** In the `main()` function of the `main.cpp` file, create a `Packet` object called `udpPacket` with `PacketType::DATA` and a protocol of `UDP`.

Call the `validatePacket()` function and the `displayInfo()` function from `udpPacket` to confirm the packet’s status and ensure it is valid.

**27.** Create a `Packet` called `tcpPacket` with a `PacketType` of `CONTROL` and a `Protocol` of `TCP`. Then call the `validatePacket()` and the `displayInfo()` functions again.

**28.** Create a `Packet` object called `unknownPacket` with `PacketType``UNKNOWN` and a `TCP``Protocol`. Then, call the `validatePacket()` and `displayInfo()` functions on this packet.

## Additional Challenge

**29.** Congratulations on creating a network packet processing system in C++!

If you would like to practice more, you can do the following:

* Try other combinations of protocols and packet types.
* Add more protocols, statuses, and packet types.
