1:ipconfig — Check Your IP Configuration
    --It displays basic IP configuration for your network adapters.
    --If you are connected through Wi-Fi, check the Wi-Fi adapter. If you are  
      using Ethernet, check the Ethernet adapter.
    --Your computer can have multiple network interfaces, each with its own IP 
      configuration.

2:ipconfig /all — Check Complete Network Details
    --This provides more information than ipconfig

3:ping — Check Network Connectivity
    --ping sends ICMP Echo Request messages to a destination and waits for ICMP 
      Echo Replies.
    --It helps determine whether a destination is reachable over the network.
    --A failed ping does not always mean the destination is down. Some servers 
      and firewalls block ICMP.
    --Ex:
        Field	                       Meaning
        bytes=32	      Size of the ICMP data payload in this example.
        time=20ms	      Approximate round-trip time for that reply.
        TTL=116	          Remaining IP Time To Live when the reply was received.
        Lost = 0	      No packets were lost in this particular test.
    --Useful variations:
        1:ping -n 10 google.com: Sends 10 ping requests instead of the default 
                                 four.
        2:ping -t 8.8.8.8: Continues pinging until you stop it using Ctrl + C.
        3:ping -4 google.com: Forces IPv4 (Ping and uses destination's IPv4 
                              address only)
        4:ping -6 google.com: Forces IPv6(Ping and uses destination's IPv6
                              address only)

4:tracert — Find the Route to a Destination
    --tracert traces the network path from your computer toward a destination.
    --It identifies intermediate routers, commonly called hops, along the route.
    --Useful variation:
        1:tracert -d google.com: Skips resolving intermediate router IP addresses 
                                 into hostnames, which can make the trace faster.
                            
5:nslookup — Check DNS Resolution
    --nslookup queries DNS (Domain Name System) servers to obtain DNS records.
    --A reverse lookup may return no name even when the IP address is active.
    --nslookup often queries a DNS server directly rather than relying on the 
      Windows DNS client cache, so it is not always a reliable way to verify that 
      the cache was cleared.

6:ipconfig /flushdns — Clear the DNS Cache
    --Windows maintains a DNS resolver cache containing certain recent DNS 
      results.
    --This command clears that local cache.
    --When is it useful? Suppose a domain recently changed its IP address, but 
                         your computer is still using a cached DNS result.
    --ipconfig /flushdns clears the Windows DNS client cache. It does not clear 
      caches held by your browser, router, or external DNS servers.

7:ipconfig /displaydns - Display the DNS Cache

8:ipconfig /release and ipconfig /renew
    --These commands are used to manage IPv4 configuration obtained through DHCP.
    --Release an IP address: ipconfig /release
        -This releases DHCP-assigned IPv4 configuration on the selected or 
         applicable adapters.
        -Your connection may temporarily lose its IPv4 address and internet 
         connectivity.
    --Request an IP address again: ipconfig /renew
        -This asks the DHCP server to renew or obtain IPv4 configuration.

9:arp -a — Check IP-to-MAC Address Mappings
    --It displays entries in the ARP cache.
    --ARP (Address Resolution Protocol) helps a device discover the MAC address 
      associated with an IPv4 address on its local network.

10:getmac — Find Your MAC Address
    --Displays MAC addresses associated with network adapters.
    --getmac /v: for extra details

11:hostname — Find Your Computer's Name
    --This displays your computer's hostname.
    --When is it useful?
        - Identifying a computer on a network.
        - Troubleshooting local network access.
        - Checking which computer you are working on.
        - Identifying a machine when using remote administration tools.

12: netstat -ano — Check Network Connections and Ports
    --It displays network connections and listening endpoints, along with their 
      local and remote addresses, connection states, and process IDs.
    --What does -ano mean?
        Option	                Purpose
        -a	        Displays listening ports and active connections.
        -n	        Displays addresses and port numbers numerically.
        -o	        Displays the owning process ID (PID), where available.
    --Suppose you want to identify the process id associated with port 8080.
            Run: netstat -ano | findstr :8080
    --This identifies the process associated with that PID.
            Run: tasklist /FI "PID eq 4321" where 4321 is PID from above command
    --Other useful variations:
        1: netstat -an: Displays connections and listening endpoints using 
                        numeric addresses.
        2:netstat -r: Displays the routing table, similar to route print.
        3:netstat -e: Displays Ethernet statistics.
    
13:route print — Check the Routing Table
    --It displays the computer's IPv4 and IPv6 routing tables.
    --The routing table helps Windows decide where to send outgoing IP packets.

14: pathping — Investigate Packet Loss Along a Route
    --pathping combines route discovery with repeated probes to estimate packet 
      loss and latency characteristics along the path.
    --It may take considerably longer than ping because it gathers statistics.

15:netsh wlan — Check Wi-Fi Information
    1:Check the current Wi-Fi connection: netsh wlan show interfaces
    2:List saved Wi-Fi profiles: netsh wlan show profiles
    3:Check available Wi-Fi networks: netsh wlan show networks

16:curl — Test Web Connectivity
        --Command: curl -I https://example.com
        --What does it do?
            curl sends an HTTP request and displays the response headers when 
            using the -I option.
        --A successful response might contain:
            HTTP/1.1 200 OK
            Content-Type: text/html
        --Why is it useful?
            Suppose: ping example.com fails, but you want to determine whether 
                     the website is accessible over HTTPS.
            Run: curl -I https://example.com
                If you receive an HTTP response, it demonstrates that the HTTP 
                request succeeded even though ping may have failed.
            This is useful because ICMP connectivity and HTTP/HTTPS connectivity 
            are different things.

17:whoami — Check Your Current User