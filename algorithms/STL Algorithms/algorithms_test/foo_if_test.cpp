   std::vector<int> numbers = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    // std::find_if
    // More @ 
    std::vector<int>::iterator it = std::find_if (numbers.begin(), numbers.end(), [](int n){    return n % 7 == 0;});
    std::cout << "Found number " << *it << std::endl;

    // std::find_if_not
    // More @ 
    it = std::find_if_not (numbers.begin(), numbers.end(), [](int n){    return n % 2 == 0;});
    std::cout << "Found number " << *it << std::endl;

    // std::count_if
    // More @ 
    int divisible_by_three = std::count_if(numbers.begin(), numbers.end(), [](int i){return i % 3 == 0;});
    std::cout << "Number of entries divisible by three " << divisible_by_three << std::endl;

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl; 

    // std::remove_if
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/remove
    // Important: note that remove_if returns pointer to first elements that satisfy the predicate,
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int n){ return n % 7 == 0;}));
    
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;    

    // std::remove_copy_if
    // More @ 

    // std::replace_if
    // More @ 

    // std::replace_copy_if
    // More @ 

    // std::copy_if
    // More @ 