   std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // count
    int count = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "Count of 5 = " << count << std::endl;
    numbers.push_back(5);
    count  = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "Count of 5 = " << count << std::endl;

    // accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of numbers in vector = " << sum << std::endl;

    // reduce
    // auto reduce = std::reduce(std::execution::par, numbers.begin(), numbers.end());
    // std::cout << "reduce        " << reduce << std::endl;

    // transform_reduce

    // partial_sum
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;
    
    std::partial_sum(numbers.begin(), numbers.end(), numbers.begin());

    std::cout << "partial_sum         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // inclusive_scan
    // std::inclusive_scan(numbers.begin(), numbers.end(), numbers.begin());
    // transform_inclusive_scan
    // exclusive_scan
    // transform_exclusive_scan

    // inner_product
    auto inner_product = std::inner_product(numbers.begin(), numbers.end(), numbers.begin(), 0);
    std::cout << "Inner Product: " << inner_product << std::endl;
    
    // adjacent_difference
    std::adjacent_difference(numbers.begin(), numbers.end(), numbers.begin());
    std::cout << "Adjacent Difference         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // sample -     
    // More at 
    std::vector<int> sample(5);
    std::sample(numbers.begin(), numbers.end(), sample.begin(), sample.size(),  std::default_random_engine(0));
    std::cout << "Random Sample         ";  for(auto& i : sample)    std::cout << i << " ";    std::cout << std::endl;

    // all_of
    if (std::all_of(numbers.cbegin(), numbers.cend(), [](int i){ return i > 0; }))
        std::cout << "All of numbers are posivite" << std::endl;

    // any_of
    if (std::any_of(numbers.cbegin(), numbers.cend(), [](int i){ return i % 2 == 0; }))
        std::cout << "At least one of numbers is even" << std::endl;

    // none_of
    if (std::none_of(numbers.cbegin(), numbers.cend(), [](int i){ return i < 0; }))
        std::cout << "None of numbers are negative" << std::endl;

    // equal
    // More at 
    std::string word = "radar";
    if(std::equal(word.begin(), word.begin() + word.size()/2, word.rbegin()))
        std::cout << word << " is palindrome" << std::endl;
    else
        std::cout << word << " is not palindrome" << std::endl;

    // is_permutation
    std::string word_one = "apple", word_two = "paple";
    if(std::is_permutation(word_one.begin(), word_one.end(), word_two.begin()))
        std::cout << word_one << " is permutation of " << word_two << std::endl;
    else
        std::cout << word_one << " is not permutation of " << word_two << std::endl;

    // lexicographical_compare
    if(std::lexicographical_compare(word_one.begin(), word_one.end(), word_two.begin(), word_two.end()))
        std::cout << word_one << " is lexicographically less than " << word_two << std::endl;
    else
        std::cout << word_one << " is lexicographically more than " << word_two << std::endl;

    // mismatch
    std::vector<int> numbers_one = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> numbers_two = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    
    auto mismatch = std::mismatch(numbers_one.begin(), numbers_one.end(), numbers_two.begin());
    std::cout << "mismatch at " << *mismatch.first << " of first and " << *mismatch.second << " of second" << std::endl;

    // find 
    // More at 
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    int find_number = 5;
    if(std::find(numbers.begin(), numbers.end(), find_number) != numbers.end())
        std::cout << "Found " << find_number << std::endl;
    else
        std::cout << "Could't find " << find_number << std::endl; 

    std::sort(numbers.begin(), numbers.end());

    // adjacent_find
    auto adj_it = std::adjacent_find(numbers.begin(), numbers.end());
    if(adj_it != numbers.end())
        std::cout << "Found adjacent " << *adj_it << "\'s in collection" << std::endl;
    else
        std::cout << "Couldn't find adjacent elements in collection" << std::endl;

    // equal_range
    numbers = {1, 2, 3, 4, 5, 5, 5, 5, 6, 7, 8, 9};
    find_number = 5;
    auto equal_range = std::equal_range(numbers.begin(), numbers.end(), find_number);
    std::cout << "First element of equal_range " << *equal_range.first << ", last element of equal range " << *equal_range.second << std::endl;

    // lower_bound
    auto lower_bound = std::lower_bound(numbers.begin(), numbers.end(), find_number);
    std::cout << "Lower bound on finding " << find_number << " is " << *lower_bound << std::endl;

    // upper_bound
    auto upper_bound = std::upper_bound(numbers.begin(), numbers.end(), find_number);
    std::cout << "Upper bound on finding " << find_number << " is " << *upper_bound << std::endl;

    // binary_search
    if(std::binary_search(numbers.begin(), numbers.end(), find_number))
        std::cout << find_number << " is in the container" << std::endl;
    else
        std::cout << find_number << " is not in the container" << std::endl;

    // search 

    // find_end

    // find_first_of

    // max_element - returns pointer to max element of the container
    auto max_element = std::max_element(numbers.begin(), numbers.end());
    std::cout << "max_element " << *max_element << std::endl;

    // min_element - returns pointer to min element of the container
    auto min_element = std::min_element(numbers.begin(), numbers.end());
    std::cout << "min_element " << *min_element << std::endl;

    // minmax_element - returns a pair of pointers to min and max elements
    auto minmax_element = std::minmax_element(numbers.begin(), numbers.end());
    std::cout << "min_element " << *minmax_element.first << " max_element " << *minmax_element.second << std::endl;