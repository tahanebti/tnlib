   std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // rotate - rotate the container (like a belt)
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/rotate
    std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    std::cout << "rotate                ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    std::cout << "rotate                ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // shuffle - shuffle elements (values of elements) in container
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/random_shuffle
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "shuffle               ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // next_permutation - get next permutation of container
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/next_permutation
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::next_permutation(numbers.begin(), numbers.end());
    std::cout << "next_permutation      ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // prev_permutation - get previous permutation
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/prev_permutation
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::prev_permutation(numbers.begin(), numbers.end());
    std::cout << "next_permutation      ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // reverse - reverse the container
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/reverse
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::reverse(numbers.begin(), numbers.end());

    std::cout << "reverse               ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;