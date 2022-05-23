
#include <iostream>

// 연관은 자기만의 규칙이 있습니다.
#include <map>

// template<typename T>
using DataType = int;
using KeyType = int;

// template<typename KeyType, typename DataType>
struct GamePair
{
    KeyType first;
    DataType second;
};

GamePair make_gamePair(const KeyType& _Key, const DataType& _Data)
{
    // 맴버가 전부다 public인 녀석은 
    return GamePair{ _Key , _Data };
}

enum class MapNodeType
{
    Error,
    Root,
    LeftChild,
    RightChild,
};


// template<typename KeyType, typename DataType>
class GameMap
{
private:
    class MapNode
    {
    public:
        GamePair Pair_;
        MapNodeType Type;
        // 0 루트
        // 1 레프트 차일드
        // 2 라이트 차일드
        // 3 MAX 에러

        MapNode* Parent_;
        MapNode* LeftChild_;
        MapNode* RightChild_;

    public:
        void FirstOrder()
        {
            // 내가 해야할일
            std::cout << Pair_.first << std::endl;
            if (nullptr != LeftChild_)
            {
                LeftChild_->FirstOrder();
            }
            if (nullptr != RightChild_)
            {
                RightChild_->FirstOrder();
            }
        }

        void MidOrder()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->MidOrder();
            }
            // 내가 해야할일
            std::cout << Pair_.first << std::endl;
            if (nullptr != RightChild_)
            {
                RightChild_->MidOrder();
            }
        }

        void LastOrder()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->MidOrder();
            }
            if (nullptr != RightChild_)
            {
                RightChild_->MidOrder();
            }
            // 내가 해야할일
            std::cout << Pair_.first << std::endl;
        }


        // 내보다 큰 부모를 찾는 함수
        MapNode* OverParent(const KeyType& _Key)
        {
            if (nullptr == Parent_)
            {
                return nullptr;
            }

            // 부모의 키가             찾으려는 키보다 작을수 있다.
            if (Parent_->Pair_.first < _Key)
            {
                return Parent_->OverParent(_Key);
            }

            return Parent_;
        }

        MapNode* NextNode()
        {
            if (nullptr != RightChild_)
            {
                return RightChild_->MinNode();
            }

            return OverParent(Pair_.first);
        }

        MapNode* MinNode()
        {
            if (nullptr == LeftChild_)
            {
                return this;
            }

            return LeftChild_->MinNode();
        }

        MapNode* MaxNode()
        {
            if (nullptr == RightChild_)
            {
                return this;
            }

            return RightChild_->MaxNode();
        }

        MapNode* Find(const KeyType& _Key)
        {
            // 내 값이 크다.

            if (Pair_.first == _Key)
            {
                return this;
            }

            if (Pair_.first > _Key)
            {
                if (nullptr == LeftChild_)
                {
                    return nullptr;
                }

                return LeftChild_->Find(_Key);
            }
            // 내 값이 더 작다.
            else if (Pair_.first < _Key)
            {
                if (nullptr == RightChild_)
                {
                    return nullptr;
                }

                return RightChild_->Find(_Key);
            }

            return nullptr;
        }

        bool Insert(const GamePair& _Pair)
        {

            // 순수하게 지금 현재 내 값이 얼마안지 
            GamePair ThisPair = Pair_;

            // 내 값이 크다.
            if (Pair_.first > _Pair.first)
            {
                if (nullptr == LeftChild_)
                {
                    LeftChild_ = new MapNode();
                    LeftChild_->Pair_ = _Pair;
                    LeftChild_->Parent_ = this;
                    LeftChild_->Type = MapNodeType::LeftChild;
                    return true;
                }

                return LeftChild_->Insert(_Pair);
            }
            // 내 값이 더 작다.
            else if (Pair_.first < _Pair.first)
            {
                if (nullptr == RightChild_)
                {
                    RightChild_ = new MapNode();
                    RightChild_->Pair_ = _Pair;
                    RightChild_->Parent_ = this;
                    RightChild_->Type = MapNodeType::RightChild;
                    return true;
                }

                return RightChild_->Insert(_Pair);
            }

            return false;
        }

        MapNode()
            : Parent_(nullptr)
            , LeftChild_(nullptr)
            , RightChild_(nullptr)
        {

        }
        ~MapNode()
        {
            MapNodeDelete();
        }

        void MapNodeDelete()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->MapNodeDelete();
                if (LeftChild_ != nullptr)
                {
                    delete LeftChild_;
                    LeftChild_ = nullptr;
                }
            }
            if (nullptr != RightChild_)
            {
                RightChild_->MapNodeDelete();
                if (RightChild_ != nullptr)
                {
                    delete RightChild_;
                    RightChild_ = nullptr;
                }
            }
        }


    };

public:
    class iterator
    {
    private:
        MapNode* Node_;

    public:
        GamePair* operator->()
        {
            return &(Node_->Pair_);
        }

        bool operator!=(const iterator& _Other) const
        {
            return Node_ != _Other.Node_;
        }

        bool operator==(const iterator& _Other) const
        {
            return Node_ == _Other.Node_;
        }

        iterator& operator++()
        {
            Node_ = Node_->NextNode();
            return *this;
        }

    public:
        iterator(MapNode* _Node)
            : Node_(_Node)
        {

        }

        iterator()
            : Node_(nullptr)
        {

        }
    };

public:
    // 시발점이 되는 노드
    MapNode* RootNode_;

    bool insert(const GamePair& _Pair)
    {
        // 체크할수밖에 없습니다.
        if (nullptr == RootNode_)
        {
            RootNode_ = new MapNode();
            RootNode_->Type = MapNodeType::Root;
            RootNode_->Pair_ = _Pair;
            return true;
        }

        return RootNode_->Insert(_Pair);
    }

    iterator Find(const KeyType& _Key)
    {
        return GameMap::iterator(RootNode_->Find(_Key));
    }

    iterator begin()
    {
        return GameMap::iterator(RootNode_->MinNode());
    }

    iterator end()
    {
        return GameMap::iterator(nullptr);
    }

    void FirstOrder() {
        RootNode_->FirstOrder();
    }

    void MidOrder() {
        RootNode_->MidOrder();
    }

    void LastOrder() {
        RootNode_->LastOrder();
    }

public:
    GameMap()
        : RootNode_(nullptr)
    {

    }

    ~GameMap()
    {
        if (nullptr != RootNode_)
        {
            delete RootNode_;
            RootNode_ = nullptr;
        }

    }
};


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {
        std::map<int, int> StdMap;
        // 같은 값은 무시되므로 값형으로 넣어줄때는 크게 신경쓸 필요가 없다.
        StdMap.insert(std::make_pair(10, 10));
        StdMap.insert(std::make_pair(10, 1));
        StdMap.insert(std::make_pair(10, 2));

        StdMap.insert(std::make_pair(30, 2));
        StdMap.insert(std::make_pair(5, 1));
        StdMap.insert(std::make_pair(7, 1));
        StdMap.insert(std::make_pair(1, 1));

        std::map<int, int>::iterator beginIter = StdMap.begin();
        std::map<int, int>::iterator endIter = StdMap.end();

        for (; beginIter != endIter; ++beginIter)
        {
            std::cout << beginIter->first << std::endl;
        }
    }

    {
        GameMap GMap;

        GMap.insert(make_gamePair(10, 10));
        GMap.insert(make_gamePair(10, 1));
        GMap.insert(make_gamePair(10, 2));
        GMap.insert(make_gamePair(5, 1));
        GMap.insert(make_gamePair(7, 1));
        GMap.insert(make_gamePair(1, 1));
        GMap.insert(make_gamePair(20, 1));
        GMap.insert(make_gamePair(25, 1));
        GMap.insert(make_gamePair(17, 1));

        std::cout << std::endl;
        std::cout << "전위 순회" << std::endl;
        GMap.FirstOrder(); // 전위순회
        std::cout << std::endl;
        std::cout << "중위 순회" << std::endl;
        GMap.MidOrder(); // 중위순회
        std::cout << std::endl;
        std::cout << "후위 순회" << std::endl;
        GMap.LastOrder(); // 후위순회

        std::cout << std::endl;
        std::cout << "이터레이터 순회" << std::endl;
        GameMap::iterator beginIter = GMap.begin();
        GameMap::iterator endIter = GMap.end();

        for (; beginIter != endIter; ++beginIter)
        {
            std::cout << beginIter->first << std::endl;
        }

        // 깊이 순회

    }
}