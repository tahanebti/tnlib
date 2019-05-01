    std::vector<std::string> animals_sort = {"elephant", "mouse", "rat", "pig", "dog", "cat", "ant", "moth"};
    std::vector<std::string> animals_stable_sort = {"elephant", "mouse", "rat", "pig", "dog", "cat", "ant", "moth"};

    // sorts container with given predicate, physical order is not guaranteed in case of equal elements
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/sort
    std::sort(animals_sort.begin(), animals_sort.end(), [](const auto& a, const auto& b) { return a.size () < b.size (); });
    std::cout << "sort                  ";  
    for(auto& i : animals_sort)    std::cout << i << " ";    
    std::cout << std::endl;

    // sorts container with given predicate, physical order is not guaranteed in case of equal elements
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/stable_sort
    std::stable_sort(animals_stable_sort.begin(), animals_stable_sort.end(), [](const auto& a, const auto& b) { return a.size () < b.size (); });
    std::cout << "stable_sort           ";  
    for(auto& i : animals_stable_sort)    std::cout << i << " ";    
    std::cout << std::endl;

    // Explanation: predicate on sorting is length of string. In this case, "rat", "pig", "dog", "cat" and "ant" all have same length
    // Since they are same length, second condition on sorting will be the physical order. In stable_sort is it guarranteed.