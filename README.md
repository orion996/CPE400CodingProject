# CPE 400 Coding Assignment
## Nick Jordy

# Project Topic 1: Dynamic routing mechanism design with focus on throughput
Create  and  simulate  a  new routing  strategy  that  maximizes  the  overall  throughput  of  a  mesh  network. Throughput  is  affected  by
many  factors  that  should  be  considered,  such  as  nodal  processing  delay, overloaded buffers, loss, etc. The more realistic assumptions you can make for your network, better it is. 

# Solution 
Throughput is the amount of data that can be sent through a network. Bandwidth, is the maximum amount of data that can be sent. If the the bandwidth is maximized, the throughput is also maximized. To find the bandwidth from any source router "src" and any destination router "dest," we calculate the minimum of the bandwidths of each hop in the path from src to dest. There are can be any number of paths between the two routers. After all the paths' bandwidths are calculated, the path with the maximum bandwidth is chosen.

# Running
Download the repository into an single folder and run 
```bash
make
./Program

```
Then enter a source Router and a destination router.

## Config File
FORMAT: <Id of Router A> <Id of Router B> <Bandwidth of the edge>; The number of vertices inthe graph is defined in the main function;
