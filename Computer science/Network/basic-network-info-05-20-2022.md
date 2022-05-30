[TIL on May 20th, 2022](../../TIL/2022/05/05-20-2022.md)
# **Summary for basic network information**

### What is a router?
> A router is a device that connects two or more packet-switched networks or subnetworks. It serves two primary functions: managing traffic between these networks by forwarding data packets to their intended IP addresses, and allowing multiple devices to use the same Internet connection.

> There are several types of routers, but most routers pass data between LANs (local area networks) and WANs (wide area networks). A LAN is a group of connected devices restricted to a specific geographic area. A LAN usually requires a single router.

> A WAN, by contrast, is a large network spread out over a vast geographic area. Large organizations and companies that operate in multiple locations across the country, for instance, will need separate LANs for each location, which then connect to the other LANs to form a WAN. Because a WAN is distributed over a large area, it often necessitates multiple routers and switches*.

> **A network switch forwards data packets between groups of devices in the same network, whereas a router forwards data between different networks.*

<br>

### Hub vs. Switch: Explore the Difference Between Hub and Switch
> A Hub helps to connect several devices to a single network and also connects segments of LAN. Hub works at the physical layer and contains many ports.

> A Switch connects multiple devices together on a single network and routes the information. The Switch uses a data link layer to work on.

<br>

### What's the DNS?
> The Domain Name System (DNS) translates domain names to IP addresses so browsers can load Internet resources.

<br>

### What is a gateway?
> A gateway is a network node used in telecommunications. Gateways serve as an entry and exit point for a network as all data must pass through or communicate with the gateway prior to being routed.

<br>

### What is DHCP?
> The Dynamic Host Configuration Protocol (DHCP) is a protocol to manage the pool of private IPs, automatically. Because the IP addresses are dynamic, addresses no longer in use are automatically returned to the pool for reallocation.

<br>

### Difference between TCP and UDP
> TCP (Transmission Control Protocol) is a connection-oriented protocol, whereas UDP (User Datagram Protocol) is a connectionless protocol. Overall, UDP is a much faster, simpler, and efficient protocol, however, retransmission of lost data packets is only possible with TCP. TCP provides an ordered delivery of data from user to server (and vice versa), whereas UDP continuously sent data to the recipient, whether or not they receive it. 

<br>

### Difference between Bandwidth and Latency
> Bandwidth is a measure of how much data can be transferred, and latency is a measure of the delay in moving that data between two nodes.

<br>

### What is MAC address?
> A media access control address (MAC address) is a unique identifier assigned to a network interface controller (NIC) for use as a network address in communications within a network segment. MAC addresses are used in the medium access control protocol sublayer of the data link layer. As typically represented, MAC addresses are recognizable as six groups of two hexadecimal digits, separated by hyphens, colons, or without a separator.

<br>

### What happens when you type a URL into your browser?
> <ol> <li> Browser looks up IP address for the domain </li> <li> Browser initiates TCP connection with the server </li> <li> Browser sends the HTTP request to the server </li> <li> Server processes request and sends back a response and </li> <li> Browser renders the content </li> </ol>

___

### Reference
- [About router](https://www.cloudflare.com/ko-kr/learning/network-layer/what-is-a-router/)
- [Difference Between Hub and Switch](https://byjus.com/gate/difference-between-hub-and-switch/#:~:text=Hub%20and%20Switch%20are%20the,send%20it%20over%20the%20network.)
- [What's DNS?](https://www.cloudflare.com/learning/dns/what-is-dns/)
- [Definition of gateway](https://www.techtarget.com/iotagenda/definition/gateway#:~:text=A%20gateway%20is%20a%20network,gateway%20prior%20to%20being%20routed.)
- [What is DHCP?](https://docs.microsoft.com/en-us/windows-server/networking/technologies/dhcp/dhcp-top#why-use-dhcp)
- [TCP vs. UDP: What’s the Difference?](https://www.lifesize.com/en/blog/tcp-vs-udp/#:~:text=TCP%20is%20a%20connection%2Doriented,is%20only%20possible%20with%20TCP.)
- [Latency and Bandwidth: Brothers from another Mother.](https://flexnetworks.ca/latency-and-bandwidth/#:~:text=Bandwidth%20is%20a%20measure%20of,size%20and%20latency%20measures%20speed.)
- [Mac Address from Wikipedia](https://en.wikipedia.org/wiki/MAC_address)
- [What happens when you type a URL into your browser?](https://aws.amazon.com/ko/blogs/mobile/what-happens-when-you-type-a-url-into-your-browser/)