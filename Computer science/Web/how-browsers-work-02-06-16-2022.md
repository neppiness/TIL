[TIL on May 16th, 2022](../../TIL/2022/06/06-16-2022.md)
# **How Browsers Work 02: Response**
- Once we have an established connection to a web server, the browser sends an initial HTTP GET request on behalf of the user, which for websites is most often an HTML file
- Once the server receives the request, it will reply with relevant response headers and the contents of the HTML

```html
<!doctype HTML>
<html>
 <head>
  <meta charset="UTF-8"/>
  <title>My simple page</title>
  <link rel="stylesheet" src="styles.css"/>
  <script src="myscript.js"></script>
</head>
<body>
  <h1 class="heading">My Page</h1>
  <p>A paragraph with a <a href="https://example.com/about">link</a></p>
  <div>
    <img src="myimage.jpg" alt="image description"/>
  </div>
  <script src="anotherscript.js"></script>
</body>
</html>
```

- This response for this initial request contains the first byte of data received
- Time to First Byte (TTFB) is the time between when the user made the request—say by clicking on a link—and the receipt of this first packet of HTML
- The first chunk of content is usually 14kB of data
- In our example above, the request is definitely less than 14KB, but the linked resources aren't requested until the browser encounters the links during parsing, described below

#### TCP Slow Start / 14KB rule
- The first response packet will be 14KB
- This is part of TCP slow start, an algorithm which balances the speed of a network connection
- Slow start gradually increases the amount of data transmitted until the network's maximum bandwidth can be determined
  * In TCP slow start, after receipt of the initial packet, the server doubles the size of the next packet to around 28KB
  * Subsequent packets increase in size until a predetermined threshold is reached, or congestion is experienced
- If you've ever heard of the 14KB rule for initial page load, TCP slow start is the reason why the initial response is 14KB, and why web performance optimization calls for focusing optimizations with this initial 14KB response in mind
- TCP slow start gradually builds up transmission speeds appropriate for the network's capabilities to avoid congestion.

### Congestion control: 혼잡 제어
- As the server sends data in TCP packets, the user's client confirms delivery by returning acknowledgements, or ACKs
- The connection has a limited capacity depending on hardware and network conditions. If the server sends too many packets too quickly, they will be dropped. Meaning, there will be no acknowledgement.
- The server registers this as missing ACKs.
- Congestion control algorithms use this flow of sent packets and ACKs to determine a send rate

___

### References
- [Populating the page: how browsers work-Response](https://developer.mozilla.org/en-US/docs/Web/Performance/How_browsers_work#response)