# ADT Specifications

- tables
    1. `Item`
        1. `int id`
        1. `string name`
        1. `double price`
        1. `int categoryId`
        1. `int storeId`
    1. `Source`
        1. `int id`
        1. `string name`
        1. `string address`
    1. `Category`
        1. `int id`
        1. `string name`
        1. `string description`
    1. `Cart`
    1. `Pending`
    1. `History`
    1. `Stock`
- `StorageBase<T>`
    1. `ItemStorage : StorageBase<Item>`
    1. `SourceStorage : StorageBase<Source>`
    1. `CartStorage : StorageBase<Cart>`
    1. `PendingStorage : StorageBase<Pending>`
    1. `HistoryStorage : StorageBase<History>`
    1. `StockStorage : StorageBase<Stock>`
- `RepositoryBase<T>`
    1. `ItemRepository : RepositoryBase<Item>`
    1. `SourceRepository : RepositoryBase<Source>`
    1. `CartRepository : RepositoryBase<Cart>`
    1. `PendingRepository : RepositoryBase<Pending>`
    1. `HistoryRepository : RepositoryBase<History>`
    1. `StockRepository : RepositoryBase<Stock>`

## `StorageBase<T>`

1. `virtual string GetDataFilename() = 0`
1. `void Load()`
1. `void Save()`
1. `vector<T>& Data()`

## `RepositoryBase<T>`

1. `RepositoryBase(const shared_ptr<StorageBase<T>>& storage)`
1. `vector<T>& GetAll()`
1. `T& Get(int id)`
    - return the reference to the item
1. `void Add(T entity)`
1. `void Save()`
1. `T& Remove(int id)`
1. `vector<T>& Sort()`
1. `vector<T>& Filter()`

Note: Turns out that the API endpoint is quite weird because of the mixed responsibilities inside `Repository`, ie. getting data (queries) and updating data (commands) - probably should use the `Command Query Separation` instead?