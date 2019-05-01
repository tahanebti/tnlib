    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Content of numbers                    ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // copy (a.k.a. deep copy)
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/copy
    std::vector<int> cpy;
    std::copy(numbers.begin(), numbers.end(), std::back_inserter(cpy));

    std::cout << "Content of cpy                        ";  
    for(auto& i : cpy)    std::cout << i << " ";    
    std::cout << std::endl;

    // move
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/move
    std::vector<int> mv;
    std::move(numbers.begin(), numbers.end(), std::back_inserter(mv));

    std::cout << "Content of mv                         ";  
    for(auto& i : mv)    std::cout << i << " ";    
    std::cout << std::endl;

    // swap_ranges
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/swap_ranges

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};

    std::cout << "Content of v1                         ";  
    for(auto& i : v1)    std::cout << i << " ";    
    std::cout << std::endl;

    std::cout << "Content of v2                         ";  
    for(auto& i : v2)    std::cout << i << " ";    
    std::cout << std::endl;

    std::swap_ranges(v1.begin(), v1.end(), v2.begin());

    std::cout << "Content of v1 after swap              ";  
    for(auto& i : v1)    std::cout << i << " ";    
    std::cout << std::endl;

    std::cout << "Content of v2 after swap              ";  
    for(auto& i : v2)    std::cout << i << " ";    
    std::cout << std::endl;

    // copy_backward
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/copy_backward

    std::copy_backward(v1.begin(), v1.begin() + 1, v1.end());

    std::cout << "Content of s2 after copy_backward     ";  
    for(auto& i : v1)    std::cout << i << " ";    
    std::cout << std::endl;

    // move_backward
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/move_backward

    std::move_backward(v2.begin(), v2.begin() + 1, v2.end());

    std::cout << "Content of s2 after move_backward     ";  
    for(auto& i : v2)    std::cout << i << " ";    
    std::cout << std::endl;