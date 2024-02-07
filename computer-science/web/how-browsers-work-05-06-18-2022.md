[TIL on June 18th, 2022](../../TIL/2022/06/06-18-2022.md)
# **How Browsers Work 05: Interactivity**

### Interactivity
- If the load includes JavaScript and only executed after the onload event fires, the main thread might be busy
- Then, scrolling, touch, and other interactions may not be available
- Time to Interactive (TTI) is the measurement of how long it took from that first request which led to the DNS lookup and SSL connection to when the page is interactive
  * Interactive being the point in time after the First Contentful Paint when the page responds to user interactions within 50ms
  * If the main thread is occupied parsing, compiling, and executing JavaScript, it is not available and therefore not able to respond to user interactions in a timely (less than 50ms) fashion

___

### References
- [Populating the page: how browsers work-Interactivity](https://developer.mozilla.org/en-US/docs/Web/Performance/How_browsers_work#interactivity)