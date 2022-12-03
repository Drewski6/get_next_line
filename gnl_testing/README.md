# Project Log
*****************************************************************

- At this point, I've made a working program that read from a file descriptor BUFFER_SIZE number of bytes, saves to a buffer then parses the buffer for \n characters and returns the segment to the calling function.
	- It works well, for all buffer sizes, but it leaks memory like crazy and does not conform to the norm.
	- To address, this, I'm going to change a few things about the code. I'm going to make the read size 1 rather than the size of the buffer. This way if I encounter a \n i can stop reading so I dont need to save a buffer. This is causing problems with leaks by leaving the buffers full on program return.
	- However, I want to save progress here in my git log because I like what I've been able to accomplish. While it's not exactly what the project needs, it's a clever way to solve a problem and if I ever need to look back on this code in the future, This is my save place.
- Moving forward:
	- Make read size 1 which will result and many more function calls and possibly less performant code.
	- This will make the assignment easier however.
