#pragma once
#include <type_traits>


struct Null { using type = Null; };


template <typename T> concept bool HasValue = 
requires
{
    { T::value < T::value } -> bool;
};


template <typename T>
concept bool TreeLike =
std::is_same<T, Null>::value ||
requires
{
    typename T::Key;
    typename T::Left;
    typename T::Right;
    typename T::Height;

    { T::Height::value } -> int;
    { T::Key::value < T::Key::value } -> bool;
};


template <int N>
struct Int
{
    using type = Int<N>;
    using next = Int<N + 1>;

    static const int value = N;
};


template <HasValue N1, HasValue N2>
struct Max
{
    using type = typename std::conditional<(N1::value > N2::value), N1, N2>::type::type;
};


template <HasValue K, typename L, typename R, typename N>
struct AVLNode
{
    using type = AVLNode<K, L, R, N>;

    using Key = K;
    using Left = L;
    using Right = R;
    using Height = N;
};


struct Less { using type = Less; };
struct More { using type = More; };
struct Equal { using type = Equal; };


template <TreeLike Tree, HasValue X> struct Find;


template<typename Tree, typename X, typename Tag> struct FindHelper;

template <typename Tree, typename X>
struct FindHelper<Tree, X, Less>
{
    using type = typename Find<typename Tree::Left, X>::type::type;
};

template <typename Tree, typename X>
struct FindHelper<Tree, X, More>
{
    using type = typename Find<typename Tree::Right, X>::type::type;
};

template <typename Tree, typename X>
struct FindHelper<Tree, X, Equal>
{
    using type = X;
};


template <TreeLike Tree, HasValue X>
struct Find
{
    using FindTag =
        typename std::conditional<(X::value < Tree::Key::value),
        Less,
        typename std::conditional<(X::value > Tree::Key::value),
        More,
        Equal>::type>::type;

    using type = typename FindHelper<Tree, X, FindTag>::type::type;

};

template <HasValue X>
struct Find<Null, X>
{
    using type = Null;
};


template <HasValue X, typename L, typename R>
struct MakeTree
{
    using type =
        typename AVLNode<
        X,
        L,
        R,
        typename Max<typename L::Height, typename R::Height>::type::next::type::type>::type::type;
};

template <HasValue X, typename L>
struct MakeTree<X, L, Null>
{
    using type =
        typename AVLNode<
        X,
        L,
        Null,
        typename L::Height::next::type>::type;
};

template <HasValue X, typename R>
struct MakeTree<X, Null, R>
{
    using type =
        typename AVLNode<
        X,
        Null,
        R,
        typename R::Height::next::type>::type;
};

template <HasValue X>
struct MakeTree<X, Null, Null>
{
    using type =
        typename AVLNode<
        X,
        Null,
        Null,
        Int<1>>::type;
};


template <typename Tree>
struct RotateLeft
{
    using type =
        typename MakeTree<
        typename Tree::Left::Key,
        typename Tree::Left::Left,
        typename MakeTree<
        typename Tree::Key,
        typename Tree::Left::Right,
        typename Tree::Right>::type::type
        >::type::type;
};

template <>
struct RotateLeft<Null>
{
    using type = Null;
};


template <typename Tree>
struct RotateRight
{
    using type =
        typename MakeTree<
        typename Tree::Right::Key,
        typename MakeTree<
        typename Tree::Key,
        typename Tree::Left,
        typename Tree::Right::Left>::type::type,
        typename Tree::Right::Right
        >::type::type;
};

template <>
struct RotateRight<Null>
{
    using type = Null;
};


template <typename Tree>
struct RotateLeftRight
{
    using type =
        typename MakeTree<
        typename Tree::Left::Right::Key,
        typename MakeTree<
        typename Tree::Left::Key,
        typename Tree::Left::Left,
        typename Tree::Left::Right::Left>::type::type,
        typename MakeTree<
        typename Tree::Key,
        typename Tree::Left::Right::Right,
        typename Tree::Right>::type::type
        >::type::type;
};


template <typename Tree>
struct RotateRightLeft
{
    using type =
        typename MakeTree<
        typename Tree::Right::Left::Key,
        typename MakeTree<
        typename Tree::Key,
        typename Tree::Left,
        typename Tree::Right::Left::Left>::type::type,
        typename MakeTree<
        typename Tree::Right::Key,
        typename Tree::Right::Left::Right,
        typename Tree::Right::Right>::type::type
        >::type::type;
};


template <typename Tree> struct Difference;

template <typename K, typename L, typename R, typename N>
struct Difference<AVLNode<K, L, R, N>>
{
    using type = typename Int<R::Height::value - L::Height::value>::type::type;
};

template <typename K, typename L, typename N>
struct Difference<AVLNode<K, L, Null, N>>
{
    using type = typename Int<(0 - L::Height::value)>::type;
};

template <typename K, typename R, typename N>
struct Difference<AVLNode<K, Null, R, N>>
{
    using type = typename R::Height;
};

template <typename K, typename N>
struct Difference<AVLNode<K, Null, Null, N>>
{
    using type = Int<0>;
};


template <typename Tree, typename N>
struct BalanceHelper
{
    using type = Tree;
};

template <typename Tree>
struct BalanceHelper<Tree, Int<2>>
{
    using type =
        typename std::conditional<(Difference<typename Tree::Right>::type::value < 0),
        RotateRightLeft<Tree>,
        RotateRight<Tree>>::type::type;
};

template <typename Tree>
struct BalanceHelper<Tree, Int<-2>>
{
    using type =
        typename std::conditional<(Difference<typename Tree::Left>::type::value > 0),
        RotateLeftRight<Tree>,
        RotateLeft<Tree>>::type::type;
};


template <typename Tree>
struct Balance
{
    using type =
        typename BalanceHelper<Tree, typename Difference<Tree>::type::type>::type::type;
};


template <typename Tree, typename X, bool Flag> struct RealInsertHelper;


template<typename Tree, typename X>
struct RealInsert
{
    using type =
        typename RealInsertHelper<Tree, X, (X::value < Tree::Key::value)>::type::type;
};

template <typename X>
struct RealInsert<Null, X>
{
    using type = typename AVLNode<X, Null, Null, Int<1>>::type;
};


template <typename Tree, typename X>
struct RealInsertHelper<Tree, X, true>
{
    using type =
        typename Balance<
        typename MakeTree<
        typename Tree::Key,
        typename RealInsert<typename Tree::Left, X>::type::type,
        typename Tree::Right>::type::type>::type::type;
};

template <typename Tree, typename X>
struct RealInsertHelper<Tree, X, false>
{
    using type =
        typename Balance<
        typename MakeTree<
        typename Tree::Key,
        typename Tree::Left,
        typename RealInsert<typename Tree::Right, X>::type::type>::type::type>::type::type;
};


template <TreeLike Tree, HasValue X>
struct Insert
{
    using type =
        typename std::conditional<std::is_same<typename Find<Tree, X>::type::type, Null>::value,
        RealInsert<Tree, X>,
        Tree>::type::type;
};

template <HasValue X>
struct Insert<Null, X>
{
    using type = AVLNode<X, Null, Null, Int<1>>;
};


template <typename Tree>
struct MakeMinInTop
{
    using Min = typename MakeMinInTop<typename Tree::Left>::type;
    using type =
        typename MakeTree<
        typename Min::Key,
        Null,
        typename Balance<
        typename MakeTree<
        typename Tree::Key,
        typename Min::Right,
        typename Tree::Right>::type::type>::type::type
        >::type::type;
};

template <typename K, typename R, typename N>
struct MakeMinInTop<AVLNode<K, Null, R, N>>
{
    using type = AVLNode<K, Null, R, N>;
};

template <>
struct MakeMinInTop<Null>
{
    using type = Null;
};


template <typename Tree, typename MinInDelete>
struct RealDeleteNotNull
{
    using type =
        typename MakeTree<
        typename MinInDelete::Key,
        typename Tree::Left,
        typename MinInDelete::Right>::type::type;
};


template <typename Tree, typename X>
struct RealDelete
{
    using MinInDelete = typename MakeMinInTop<typename Tree::Right>::type::type;
    using type =
        typename std::conditional<std::is_same<MinInDelete, Null>::value,
        Null,
        RealDeleteNotNull<Tree, MinInDelete>>::type::type;
};


template <TreeLike Tree, HasValue X> struct Delete;


template <typename Tree, typename X, typename Tag> struct DeleteHelper;

template <typename Tree, typename X>
struct DeleteHelper<Tree, X, Less>
{
    using type =
        typename Balance<
        typename MakeTree<typename Tree::Key,
        typename Delete<typename Tree::Left, X>::type::type,
        typename Tree::Right>::type::type
        >::type::type;
};

template <typename Tree, typename X>
struct DeleteHelper<Tree, X, More>
{
    using type =
        typename Balance<
        typename MakeTree<typename Tree::Key,
        typename Tree::Left,
        typename Delete<typename Tree::Right, X>::type::type>::type::type
        >::type::type;
};

template <typename Tree, typename X>
struct DeleteHelper<Tree, X, Equal>
{
    using type =
        typename std::conditional<(std::is_same<typename Tree::Left, Null>::value),
        typename Tree::Right,
        typename std::conditional<(std::is_same<typename Tree::Right, Null>::value),
        typename Tree::Left,
        typename RealDelete<Tree, X>::type::type
        >::type::type
        >::type::type;
};


template <TreeLike Tree, HasValue X>
struct Delete
{
    using DeleteTag =
        typename std::conditional<(X::value < Tree::Key::value),
        Less,
        typename std::conditional<(X::value > Tree::Key::value),
        More,
        Equal>::type>::type;

    using type =
        typename std::conditional<std::is_same<typename Find<Tree, X>::type::type, Null>::value,
        Tree,
        DeleteHelper<Tree, X, DeleteTag>>::type::type;
};

template <HasValue X>
struct Delete<Null, X>
{
    using type = Null;
};
