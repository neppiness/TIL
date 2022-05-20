[TIL on May 20th, 2022](../../TIL/2022/05-20-2022.md)
# **Summarize subnetwork**

### What is subnetting?
> A subnetwork or subnet is a logical subdivision of an IP network. The practice of dividing a network into two or more networks is called subnetting.

<br>

### Two fields of the logical division of an IP address
> Computers that belong to the same subnet are addressed with an identical most-significant bit-group in their IP addresses. 

> This results in the logical division of an IP address into two fields: the network number or routing prefix and the rest field or host identifier.

- #### Host identifier
> The rest field is an identifier for a specific host or network interface.

- #### The routing prefix
> The routing prefix may be expressed in Classless Inter-Domain Routing (CIDR) notation written as the first address of a network, followed by a slash character (/), and ending with the bit-length of the prefix.

> ex) 198.51.100.0/24 is the prefix of the IPv4 network starting at the given address, having 24 bits allocated for the network prefix, and the remaining 8 bits reserved for host addressing. Addresses in the range 198.51.100.0 to 198.51.100.255 belong to this network

- #### Subnet broadcast address
> An IP in identical subnet with a host identifier of all 1s (the address 198.51.100.255 for an example) is used as the subnet broadcast address.

<br>

### Subnet mask
> If any IP is applied by a bitwise AND operation to the subnet mask yields to the routing prefix

> Subnet masks are also expressed in dot-decimal notation like an IP address. For example, the prefix 198.51.100.0/24 would have the subnet mask 255.255.255.0.

___

### Reference
- [Subnetwork from Wikipedia](https://en.wikipedia.org/wiki/Subnetwork)