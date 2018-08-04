#include <string>
#include <vector>
#include <memory>

using namespace std;

class Item
{
private:
    int _id;
    string _name;
    int categoryId;
};

class Price
{
private:
    int _id;
    int _itemId;
    int _sourceId;
    double _price;
};

class Source
{
private:
    int _id;
    string _name;
    string _address;
};


template<class T>
class StorageBase
{
private:
    vector<T> _data;

public:
    void Load()
    {

    }
    void Save()
    {
        
    }
    virtual string GetFilename() = 0;
    vector<T>& Data() { return _data; }
};

class ItemStorage : public StorageBase<Item>
{
public:
    void string GetFilename() override
    {
        return "items.json";
    }
};

class GetAllItemsQuery
{
private:
    shared_ptr<ItemStorage> _storage;

public:
    GetAllItemsQuery(const shared_ptr<ItemStorage>& storage) 
        : _storage(storage)
    {}

    template<class TSelector, class TPredicate>
    vector<Item>& Execute(optional<TSelector> sortSelector, optional<TPredicate> filterPredicate)
    {
        // https://github.com/coveo/linq
        vector<Item>& data = _storage->Data();
        if (sortSelector.check_if_has_value)
        {
            sort(data, sortSelector);
        }
        // TODO: how to filter while preseving the reference to the original item in Storage
        
        return data;
    }
};

template<class TSelector>
void sort(vector<Item>& items, TSelector fieldSelector)
{
    for (;;) 
    {
        for (;;)
        {
            if (fieldSelector(items.at(i)) > fieldSelector(items.at(j))
            {
                //swap vector position;
                                                                
            }
        }
    }
}

sort(items, [&](Item item) { return item.name; })
Execute(sortSelector, [&](Item item) { return item.name == "hi" || item.id < 10 || item.quantity == 0;})


class UpdateItemCommand
{
public:
    // https://www.boost.org/doc/libs/1_67_0/libs/optional/doc/html/index.html
    // https://theboostcpplibraries.com/boost.optional
    void Execute(optional<string> name, optional<int> categoryId)
    {

    }    
};

void main()
{
    shared_ptr<ItemStorage> itemStorage = make_shared<ItemStorage>();

    GetAllItemsQuery query{itemStorage};
    vector<Item>& data = query.Execute();
    data.at(0)._id = 1;

    itemStorage->Save();
}


// camelCase    -> local variable
// _camelCase   -> private/protected variable
// PascalCase   -> function name
// SCREAMING_SNAKE_CASE  -> constant
// snake_case  -> filename

// boost
// https://www.boost.org/
