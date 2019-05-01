    std::set<int> s1 {1, 2, 5, 5, 5, 9};
    std::set<int> s2 {2, 5, 7};
    std::set<int> sdiff;
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(sdiff, sdiff.begin()));

    std::cout << "Set difference is             ";
    for(auto& i : sdiff)    std::cout << i << " ";
    std::cout << std::endl;

    // Note that sorted vector (or any other container) is also considered a set
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/set_difference
    std::vector<int> v1 {1, 2, 5, 5, 5, 9};
    std::vector<int> v2 {2, 5, 7};
    std::vector<int> vdiff;
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::inserter(vdiff, vdiff.begin()));

    std::cout << "Set (vector) difference is    ";
    for(auto& i : sdiff)    std::cout << i << " ";
    std::cout << std::endl;

    // set_intersection
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/set_intersection
    std::set<int> sinter;
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(sinter, sinter.begin()));

    std::cout << "Set intersection is           ";
    for(auto& i : sinter)    std::cout << i << " ";
    std::cout << std::endl;    
    
    // set_union
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/set_union
    std::set<int> sunion;
    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(sunion, sunion.begin()));

    std::cout << "Set union is                  ";
    for(auto& i : sunion)    std::cout << i << " ";
    std::cout << std::endl;    

    // set_symmetric_difference
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/set_symmetric_difference
    std::set<int> ssymdiff;
    std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(ssymdiff, ssymdiff.begin()));

    std::cout << "Set symmetric difference is   ";
    for(auto& i : ssymdiff)    std::cout << i << " ";
    std::cout << std::endl;  

    // includes 
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/includes
    bool includes = std::includes(s1.begin(), s1.end(), s2.begin(), s2.end());
    std::cout << "s1 includes s2?               " << includes << std::endl;

    // merge
    // More @ https://e...content-available-to-author-only...e.com/w/cpp/algorithm/merge
    std::set<int> dst;
    std::merge(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(dst, dst.end()));

    std::cout << "Content of dst                ";  
    for(auto& i : dst)    std::cout << i << " ";    
    std::cout << std::endl;