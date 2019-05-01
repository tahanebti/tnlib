   // fill 
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/fill
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::fill(numbers.begin(), numbers.end(), -1);

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // generate
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/generate
    std::generate(numbers.begin(), numbers.end(), [n = 0] () mutable { return n++; });

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // iota
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/iota
    std::iota(numbers.begin(), numbers.end(), 42);

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // replace
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/replace
    std::replace(numbers.begin(), numbers.end(), 42, 43);

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;