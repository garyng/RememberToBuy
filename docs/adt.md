# ADT Specifications

- tables
    1. Item
        1. int id
        1. string name
        1. int categoryId
    1. ItemSource
        1. int id
        1. int itemId
        1. int sourceId
        1. double price
    1. Source
        1. int id
        1. string name
        1. string address
    1. Category
        1. int id
        1. string name
        1. string description
    1. CartItem
        1. int id
        1. int itemId
        1. int quantity
        1. int sourceId
    1. PendingItem
        1. int id
        1. int itemId
        1. int quantity
    1. HistoryItem
        1. int id
        1. int itemId
        1. int quantity
        1. int sourceId
        1. double price
        1. string date
    1. StockItem
        1. int id
        1. int itemId
        1. int quantity
- StorageBase<T>
    - void Load()
    - void Save()
    - virtual string GetFileName() = 0
    - LinkedList<T>& Data()
    - subclasses
        1. ItemStorage : public StorageBase<Item>
        1. SourceStorage : public StorageBase<Source>
        1. CartItemStorage : public StorageBase<Cart>
        1. PendingItemStorage : public StorageBase<PendingItem>
        1. HistoryItemStorage : public StorageBase<HistoryItem>
        1. StockItemStorage : public StorageBase<StockItem>
- Commands
    - Update
        1. UpdateCartItemQuantityCommand
            1. UpdateCartItemQuantityCommand(const shared_ptr<CartItemStorage>& storage)
                1. construct the command object using the specified storage
            1. void Execute(int cartItemId, int quantity)
                1. {
                    1. _storage->Data().at(0).quantity(10);
                    1. _storage->Save();
                1. }
        1. UpdatePendingItemQuantityCommand
            1. UpdatePendingItemQuantityCommand(const shared_ptr<PendingItemStorage>& storage)
            1. void Execute(int pendingItemId, int quantity)
        1. UpdateHistoryItemQuantityCommand
            1. UpdateHistoryItemQuantityCommand(const shared_ptr<HistoryItemStorage>& storage)
            1. void Execute(int historyItemId, int quantity)
        1. UpdateStockItemQuantityCommand
            1. UpdateStockItemQuantityCommand(const shared_ptr<StockItemStorage>& storage)
            1. void Execute(int stockItemId, int quantity)
    - Delete
        1. DeleteCartItemCommand
            1. DeleteCartItemCommand(const shared_ptr<CartItemStorage>& storage)
            1. void Execute(int cartItemId)
        1. DeletePendingItemCommand
            1. DeletePendingItemCommand(const shared_ptr<PendingItemStorage>& storage)
            1. void Execute(int pendingItemId)
        1. DeleteHistoryItemCommand
            1. DeleteHistoryItemCommand(const shared_ptr<HistoryItemStorage>& storage)
            1. void Execute(int historyItemId)
        1. DeleteStockItemCommand
            1. DeleteStockItemCommand(const shared_ptr<StockItemStorage>& storage)
            1. void Execute(int stockItemId)
    - Add
        1. AddPendingItemCommand
            1. AddPendingItemCommand(const shared_ptr<PendingItem>& storage)
            1. void Execute(int pendingItemId, int quantity)
        1. MovePendingItemToCartCommand
            1. MovePendingItemToCartCommand(const shared_ptr<PendingItemStorage>& pendingItemStorage, const shared_ptr<CartItemStorage>& cartItemStorage)
            1. void Execute(int pendingItemId)
        1. CompleteCartItemCommand
            1. CompleteCartItemCommand(const shared_ptr<CartItemStorage>& cartItemStorage, const shared_ptr<HistoryItemStorage>& historyItemStorage, const shared_ptr<StockItemStorage>& stockItemStorage)
            1. void Execute(int cartItemId)
- Queries
    1. GetById
        1. GetItemById
            1. GetItemById(const shared_ptr<ItemStorage>& storage)
                1. construct the query object using the specified storage
            1. Item Execute(int id)
                1. return the item with the matching id
        1. GetItemSourceById
            1. GetItemSourceById(const shared_ptr<ItemSourceStorage>& storage)
            1. ItemSource Execute(int id)
        1. GetSourceById
            1. GetSourceById(const shared_ptr<SourceStorage>& storage)
            1. Source Execute(int id)
        1. GetCategoryById
            1. GetCategoryById(const shared_ptr<CategoryStorage>& storage)
            1. Category Execute(int id)
        1. GetCartItemById
            1. GetCartItemById(const shared_ptr<CartItemStorage>& storage)
            1. CartItem Execute(int id)
        1. GetPendingItemById
            1. GetPendingItemById(const shared_ptr<PendingItemStorage>& storage)
            1. PendingItem Execute(int id)
        1. GetHistoryItemById
            1. GetHistoryItemById(const shared_ptr<HistoryItemStorage>& storage)
            1. HistoryItem Execute(int id)
    1. GetAll
        1. GetAllItems
            1. GetAllItems(const shared_ptr<Item>& storage)
            1. LinkedList<Item>& Execute()
        1. GetAllItemSources
            1. GetAllItemSources(const shared_ptr<ItemSource>& storage)
            1. LinkedList<ItemSource>& Execute()
        1. GetAllSources
            1. GetAllSources(const shared_ptr<Source>& storage)
            1. LinkedList<Source>& Execute()
        1. GetAllCategories
            1. GetAllCategories(const shared_ptr<Categories>& storage)
            1. LinkedList<Category>& Execute()
        1. GetAllCartItems
            1. GetAllCartItems(const shared_ptr<CartItem>& storage)
            1. LinkedList<CartItem>& Execute()
        1. GetAllPendingItems
            1. GetAllPendingItems(const shared_ptr<PendingItem>& storage)
            1. LinkedList<PendingItem>& Execute()
        1. GetAllHistoryItems
            1. GetAllHistoryItems(const shared_ptr<HistoryItem>& storage)
            1. LinkedList<HistoryItem>& Execute()
- LinkedList<T>
    1. void Add(T element)
        - add the specified element to the end of the list
    1. T Remove(int index)
        - remove and return the element at the specified index
    1. T& Get(int index)
        - return the reference to the element at the specified index
    1. template<class TSelector>
        void SortBy(TSelector selector, bool isAscending = true)
        - sort the list according to the value returned by selector
    1. template<class TPredicate>
        LinkedList<T> FilterBy(TPredicate predicate)
    1. template<class TKeySelector, class TKey>
        map<TKey, LinkedList<T>> GroupBy(TKeySelector selector)
        - group the elements according the key returned by the selector
        {
            map<TKey, LinkedList<T>> groups;
            for (autoz& item : items)
            {
                auto key = selector(item);
                if (groups.check_if_key_exist(key)      // pseudocode
                {
                    groups.get_key(key).Add(item);
                }
                else
                {
                    LinkedList list;
                    list.Add(item);
                    groups.add_key_value(key, list);
                }
            }
        }

        GroupBy(items, [](Item item) { return item.date.year; })
