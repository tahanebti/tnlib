   std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 9, 10};

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Basic sort
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/sort
    std::cout << "sort              ";
    std::sort(numbers.begin(), numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Partial sort
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/partial_sort
    std::cout << "partial_sort      ";
    std::partial_sort(numbers.begin(), numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // n'th element sort - element that would be in n'th position if the collection was sorted
    // More at https://e...content-available-to-author-only...e.com/w/cpp/algorithm/nth_element
    std::cout << "nth_element       ";
    std::nth_element(numbers.begin(), numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Sort heap
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/sort_heap
    std::make_heap(numbers.begin(), numbers.end());
    std::sort_heap(numbers.begin(), numbers.end());
    std::cout << "sort_heap         ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Inplace Merge 
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/inplace_merge
    std::sort(numbers.begin(), numbers.begin() + 5);

    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;    

    std::cout << "Current State     ";
    std::sort(numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::inplace_merge(numbers.begin(), numbers.begin() + 5, numbers.end());
    std::cout << "inplace_merge     ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;