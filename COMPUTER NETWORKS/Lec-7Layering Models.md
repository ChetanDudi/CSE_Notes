-->Layering: Layering is a technique of dividing a complex networking task into 
             smaller, logically organized parts called layers, where each layer 
             performs a specific set of functions and works with the layers above 
             and below it.
    Each layer has its own responsibility, so the entire communication process 
    becomes easier to design, understand, troubleshoot, and maintain.

-->Layering solves this problem in several ways.
    1. Reduces complexity:
        - Each layer handles a specific responsibility.
        - We can understand or develop one part without understanding every 
          detail of the entire network.
    2. Provides modularity:
    - Each layer works as a separate logical module.
    - Changes inside one layer generally do not require redesigning every other 
      layer, provided the interfaces and expected services remain compatible.
    3. Supports standardization:
    - Different companies can develop networking devices and software that 
      communicate using common standards.
    - For example, a laptop made by one company can communicate with a router 
      made by another company.
    4. Makes troubleshooting easier:
    - If a website does not load, we can investigate different parts of the 
      communication process.
    - For example, check the Wi-Fi connection, IP connectivity, transport 
      connection, and application-level response.
    5. Encourages interoperability:
    - Different operating systems, applications, and network devices can work 
      together by following compatible protocols and standards.

-->Encapsulation: As data moves downward, layers may add their own control 
           information, usually in the form of headers and sometimes trailers.
           This process is called encapsulation.

-->Decapsulation: The receiver's layers process and remove the relevant protocol  
           information to recover the data. This reverse process is called 
           decapsulation.

->Limitations of Layering:
        1: Adds protocol headers and processing overhead

-->The two major networking reference models are:
    1. OSI Model — 7 layers.
    2. TCP/IP Model — commonly 4 layers.