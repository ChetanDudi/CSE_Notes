-->MAC Address: It stands for Media Access Control and used when we need to send data to 
                interface of the device.
        ->Every node is identified with the help of MAC in the internet.
        ->It is physical or hardware address, unique, cannot be changed, assigned by the 
          manufacturer.
        ->It is 48 bits long (6 octects)
        ->Switches needs MAC Addresses to forward data while Routers uses IP Addresses to 
          forwward data.
        ->It is colon (:) or hyphen (-) separated for each octect. Each ectect is made up 
          of two hexadecials numbers.
        ->The first half (starting 3 bytes or 3 octects) are known as OUI 
          (Organisationally Unique Identifier) to identify the manufacturer of that 
          hardware device.
        ->The second half (last 3 bytes or 3 octects) actually identify difference between 
          each manufacturer as well.
        ->To view MAC Address use "ipconfig/all" in cmd.
    IP=Location of the person
    MAC=Name of the person

-->IP Address vs MAC Address:
    1: IP Address: A logical address used to identify a device/interface and enable 
                   communication between different networks.
        -> Works at Network Layer (Layer 3).
        -> IPv4 = 32 bits, IPv6 = 128 bits.
        -> Can change when the device connects to a different network.
        -> Used by routers for routing packets.
        -> Example: 192.168.1.10

    2: MAC Address: A link-layer address used to identify a network interface for 
                    communication within the local network/link.
        -> Works at Data Link Layer (Layer 2).
        -> Ethernet MAC is typically 48 bits (6 bytes).
        -> Usually assigned to the network interface, but it can be changed/spoofed in 
           software, so it is not strictly permanent.
        -> Used for local frame delivery.
        -> Example: 00:1A:2B:3C:4D:5E

    3: IP vs MAC — Main Difference:
        -> IP = logical address → tells where the device is on the network.
        -> MAC = link-layer address → identifies the interface on the local link.
        -> IP → used for routing between networks.
        -> MAC → used for delivery on the current local network/link.

    4: How They Work Together:
        -> When sending IPv4 data on an Ethernet LAN, ARP maps an IP address to the 
           corresponding MAC address.
        -> The IP address remains relevant for the packet's Layer-3 routing.
        -> The MAC addresses are used in the Layer-2 frame for the current link.
        -> At each routed hop, the Layer-2 frame is for that particular link; the IP 
           packet is carried onward toward its destination.

    5: Easy Way to Remember:
        -> IP = Where? → Network/location for routing.
        -> MAC = Which interface on this link? → Local delivery.
        -> ARP = IP → MAC mapping for IPv4 local-link delivery.

    

