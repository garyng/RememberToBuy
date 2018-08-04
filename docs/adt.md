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
            1. UpdateCartItemQuantityCommand(shared_ptr<CartItemStorage>& storage)
            1. void Execute(int cartItemId, int quantity)
                1. {
                    1. _storage->Data().at(0).quantity(10);
                    1. _storage->Save();
                1. }
        1. UpdatePendingItemQuantityCommand
            1. UpdatePendingItemQuantityCommand(shared_ptr<PendingItemStorage>& storage)
            1. void Execute(int pendingItemId, int quantity)
        1. UpdateHistoryItemQuantityCommand
            1. UpdateHistoryItemQuantityCommand(shared_ptr<HistoryItemStorage>& storage)
            1. void Execute(int historyItemId, int quantity)
        1. UpdateStockItemQuantityCommand
            1. UpdateStockItemQuantityCommand(shared_ptr<StockItemStorage>& storage)
            1. void Execute(int stockItemId, int quantity)
    - Delete
        1. DeleteCartItemCommand
            1. DeleteCartItemCommand(shared_ptr<CartItemStorage>& storage)
            1. void Execute(int cartItemId)
        1. DeletePendingItemCommand
            1. DeletePendingItemCommand(shared_ptr<PendingItemStorage>& storage)
            1. void Execute(int pendingItemId)
        1. DeleteHistoryItemCommand
            1. DeleteHistoryItemCommand(shared_ptr<HistoryItemStorage>& storage)
            1. void Execute(int historyItemId)
        1. DeleteStockItemCommand
            1. DeleteStockItemCommand(shared_ptr<StockItemStorage>& storage)
            1. void Execute(int stockItemId)
    - Add
        1. AddPendingItemCommand
            1. void Execute(int pendingItemId, int quantity)
        1. MovePendingItemToCartCommand
            1. void Execute(int pendingItemId)
        1. CompleteCartItemCommand
            1. void Execute(int cartItemId)
        1. CopyCartItemToStockCommand
            1. void Execute(int cartItemId)
- Queries
    1. GetById
        1. GetItemById
            1. GetItemById(shared_ptr<ItemStorage>& storage)
            1. Item Execute(int id)
        1. GetItemSourceById
            1. GetItemSourceById(shared_ptr<ItemSourceStorage>& storage)
            1. ItemSource Execute(int id)
        1. GetSourceById
            1. GetSourceById(shared_ptr<SourceStorage>& storage)
            1. Source Execute(int id)
        1. GetCategoryById
            1. GetCategoryById(shared_ptr<CategoryStorage>& storage)
            1. Category Execute(int id)
        1. GetCartItemById
            1. GetCartItemById(shared_ptr<CartItemStorage>& storage)
            1. CartItem Execute(int id)
        1. GetPendingItemById
            1. GetPendingItemById(shared_ptr<PendingItemStorage>& storage)
            1. PendingItem Execute(int id)
        1. GetHistoryItemById
            1. GetHistoryItemById(shared_ptr<HistoryItemStorage>& storage)
            1. HistoryItem Execute(int id)
    1. GetAll
        1. GetAllItems
            1. GetAllItems(shared_ptr<Item>& storage)
        1. GetAllItemSources
            1. GetAllItemSources(shared_ptr<ItemSource>& storage)
        1. GetAllSources
            1. GetAllSources(shared_ptr<Source>& storage)
        1. GetAllCategories
            1. GetAllCategories(shared_ptr<Categorie>& storage)
        1. GetAllCartItems
            1. GetAllCartItems(shared_ptr<CartItem>& storage)
        1. GetAllPendingItems
            1. GetAllPendingItems(shared_ptr<PendingItem>& storage)
        1. GetAllHistoryItems
            1. GetAllHistoryItems(shared_ptr<HistoryItem>& storage)
- LinkedList<T>
    1. void Add(T item)
    1. T Remove(int index)
    1. T& Get(int index)
    1. template<class TSelector>
        void SortBy(TSelector selector, bool isAscending = true)
    1. template<class TPredicate>
        void FilterBy(TPredicate predicate)