//
//  computer_architecture
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//


/**
    Notes :

    COMPILE TIME: Action performed during compilation; uses no execution time.
    RUN TIME: Action performed during program execution

    CPU MEMORY LOCATIONS
    REGISTERS : Physical Temporary storage for processing data/calculations taken from cache
    CACHES : Physical Temporary storage for frequently accessed data for rapid access taken from RAM
    RANDOM ACCESS MEMORY (RAM) : Physical Main memory where everything is held for execution
    • Virtual memory is memory on hard drive extending RAM

    • Segmentation Fault: Attempt to access RAM location that the CPU cannot physically access
    • STACK : LIFO Segment storing temporary/local/value-type variables and keeps track of program execution
        • Has limit on size, Fast access
        • Operations on objects are usually faster
        • Stack overflow caused if large stack allocation or recursion gone wrong
    • HEAP : Segment storing dynamically allocated reference-type variables
        • Larger size than stack though slower as it uses pointers to access
        • Segmentation fault caused if accessing memory after its deleted
**/


        