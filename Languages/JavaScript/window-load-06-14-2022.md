[TIL on May 16th, 2022](../../TIL/2022/06/06-14-2022.md)
# **About Window Load**
- Interface: event
- Related events: load, DOMContentLoaded, readystatechange, beforeunload, unload

### load
- When the page is completely loaded including style sheet and script as well

> The load event is fired when the whole page has loaded, including all dependent resources such as stylesheets and images

### DOMContentLoaded
> The DOMContentLoaded event fires when the initial HTML document has been completely loaded and parsed, without waiting for stylesheets, images, and subframes to finish loading.

#### load vs. DOMContentLoaded
> load should be used only to detect a fully-loaded page

### unload
> The unload event is fired when the document or a child resource is being unloaded

> Warning: Developers should avoid using this event
> Especially on mobile, the unload event is not reliably fired

#### It is fired after:
- beforeunload (cancelable event)
- pagehide

#### The document is in the following state:
- All the resources still exist (img, iframe etc.)
- Nothing is visible anymore to the end user
- UI interactions are ineffective (window.open, alert, confirm, etc.)
- An error won't stop the unloading workflow

For more information, check [the related reference](https://developer.mozilla.org/en-US/docs/Web/API/Window/unload_event)


### beforeunload
> The beforeunload event is fired when the window, the document and its resources are about to be unloaded. The document is still visible and the event is still cancelable at this point.

For more information, check [the related reference](https://developer.mozilla.org/en-US/docs/Web/API/Window/beforeunload_event)

___

### Reference
- [load event](https://developer.mozilla.org/en-US/docs/Web/API/Window/load_event)
- [DOMContentLoaded event](https://developer.mozilla.org/en-US/docs/Web/API/Document/DOMContentLoaded_event)
- [unload event](https://developer.mozilla.org/en-US/docs/Web/API/Window/unload_event)
- [before unloaded](https://developer.mozilla.org/en-US/docs/Web/API/Window/beforeunload_event)