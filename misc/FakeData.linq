<Query Kind="Program">
  <NuGetReference>Bogus</NuGetReference>
  <Namespace>Bogus</Namespace>
  <Namespace>Bogus.Bson</Namespace>
  <Namespace>Bogus.DataSets</Namespace>
  <Namespace>Bogus.Distributions.Gaussian</Namespace>
  <Namespace>Bogus.Extensions</Namespace>
  <Namespace>Bogus.Extensions.Brazil</Namespace>
  <Namespace>Bogus.Extensions.Canada</Namespace>
  <Namespace>Bogus.Extensions.Denmark</Namespace>
  <Namespace>Bogus.Extensions.Extras</Namespace>
  <Namespace>Bogus.Extensions.Finland</Namespace>
  <Namespace>Bogus.Extensions.Italy</Namespace>
  <Namespace>Bogus.Extensions.Portugal</Namespace>
  <Namespace>Bogus.Extensions.UnitedKingdom</Namespace>
  <Namespace>Bogus.Extensions.UnitedStates</Namespace>
  <Namespace>Bogus.Platform</Namespace>
  <Namespace>Bogus.Premium</Namespace>
</Query>

void Main()
{
	//	FakeCartItems()
	//		.Generate(10)
	//		.Dump();
	var categories = FakeCategories().Generate(10); //.Dump();
	var items = FakeItems(categories).Generate(50); //.Dump();.Dump();
	var sources = FakeSources().Generate(10); //.Dump();.Dump();
	var itemSources = FakeItemSources(items, sources).Generate(100); //.Dump();.Dump();
	var cartItems = FakeCartItems(items, itemSources).Generate(10); //.Dump();.Dump();
	var historyItems = FakeHistoryItems(items, itemSources).Generate(20); //.Dump();.Dump();
	var pendingItems = FakePendingItems(items).Generate(20); //.Dump();.Dump();
	var stockItems = FakeStockItems(items).Generate(20); //.Dump();.Dump();

	Join(categories).Dump("categories");
	Join(items).Dump("items");
	Join(sources).Dump("sources");
	Join(itemSources).Dump("itemSources");
	Join(cartItems).Dump("cartItems");
	Join(historyItems).Dump("historyItems");
	Join(pendingItems).Dump("pendingItems");
	Join(stockItems).Dump("stockItems");



}

string Join<T>(IEnumerable<T> items)
{
	return string.Join("," + Environment.NewLine, items);
}

Faker<Item> FakeItems(IEnumerable<Category> categories)
{
	return new Faker<Item>()
		.Rules((f, i) =>
		{
			i.Id = f.IndexFaker;
			i.Name = f.Commerce.ProductName();
			i.CategoryId = f.PickRandom(categories).Id;
		});
}
Faker<Category> FakeCategories()
{
	return new Faker<Category>()
		.Rules((f, c) =>
		{
			c.Id = f.IndexFaker;
			c.Name = f.Commerce.Categories(1)[0];
			c.Description = f.Lorem.Sentence();
		});
}
Faker<Source> FakeSources()
{
	return new Faker<Source>()
		.Rules((f, s) =>
		{
			s.Id = f.IndexFaker;
			s.Name = f.Company.CompanyName();
			s.Address = f.Address.FullAddress();

		});
}
Faker<ItemSource> FakeItemSources(IEnumerable<Item> items, IEnumerable<Source> sources)
{
	int length = items.Count();
	return new Faker<ItemSource>()
		.Rules((f, i) =>
		{
			i.Id = f.IndexFaker;
			i.ItemId = items.ElementAt(i.Id % length).Id;
			i.SourceId = f.PickRandom(sources).Id;
			i.Price = f.Random.Double(1, 100);
		});
}
Faker<CartItem> FakeCartItems(IEnumerable<Item> items, IEnumerable<ItemSource> itemSources)
{
	return new Faker<CartItem>()
		.Rules((f, ci) =>
		{
			ci.Id = f.IndexFaker;
			ci.ItemId = f.PickRandom(items).Id;
			ci.Quantity = f.Random.Int(0, 10);
			ci.SourceId = f.PickRandom(itemSources.Where(s => s.ItemId == ci.Id)).SourceId;
		});
}
Faker<HistoryItem> FakeHistoryItems(IEnumerable<Item> items, IEnumerable<ItemSource> itemSources)
{
	return new Faker<HistoryItem>()
		.Rules((f, hi) =>
		{
			hi.Id = f.IndexFaker;
			hi.ItemId = f.PickRandom(items).Id;
			hi.Quantity = f.Random.Int(0, 100);
			hi.SourceId = f.PickRandom(itemSources.Where(s => s.ItemId == hi.Id)).SourceId;
			hi.Price = f.Random.Double(1, 100);
			hi.Date = f.Date.Recent().ToString();
		});
}
Faker<PendingItem> FakePendingItems(IEnumerable<Item> items)
{
	return new Faker<PendingItem>()
		.Rules((f, pi) =>
		{
			pi.Id = f.IndexFaker;
			pi.ItemId = f.PickRandom(items).Id;
			pi.Quantity = f.Random.Int(0, 100);
		});
}

Faker<StockItem> FakeStockItems(IEnumerable<Item> items)
{
	return new Faker<StockItem>()
		.Rules((f, si) =>
		{
			si.Id = f.IndexFaker;
			si.Quantity = f.Random.Int(0, 100);
			si.ItemId = f.PickRandom(items).Id;

		});
}
// Define other methods and classes here

public static class Dump
{
	public static string DumpType<T>(T @this)
	{
		return "{" + string.Join(", ",
				@this
					.GetType()
					.GetProperties()
					.Select(p =>
					{
						object value = p.GetValue(@this);
						switch (value)
						{
							case int number:
								return number.ToString();
							case string str:
								return $"\"{str}\"";
							default:
								return value;
						}
					})) + "}";

	}
}
public class CartItem
{
	public int Id { get; set; }
	public int ItemId { get; set; }
	public int Quantity { get; set; }
	public int SourceId { get; set; }

	public override string ToString()
	{
		return Dump.DumpType(this);
	}
}
public class Item
{
	public int Id { get; set; }
	public string Name { get; set; }
	public int CategoryId { get; set; }

	public override string ToString()
	{
		return Dump.DumpType(this);
	}
}
public class Category
{
	public int Id { get; set; }
	public string Name { get; set; }
	public string Description { get; set; }

	public override string ToString()
	{
		return Dump.DumpType(this);
	}
}
public class HistoryItem
{
	public int Id { get; set; }
	public int ItemId { get; set; }
	public int Quantity { get; set; }
	public int SourceId { get; set; }
	public double Price { get; set; }
	public string Date { get; set; }


	public override string ToString()
	{
		return Dump.DumpType(this);
	}
}
public class ItemSource
{
	public int Id { get; set; }
	public int ItemId { get; set; }
	public int SourceId { get; set; }
	public double Price { get; set; }


	public override string ToString()
	{
		return Dump.DumpType(this);
	}
}
public class PendingItem
{
	public int Id { get; set; }
	public int ItemId { get; set; }
	public int Quantity { get; set; }

	public override string ToString()
	{
		return Dump.DumpType(this);
	}
}
public class Source
{
	public int Id { get; set; }
	public string Name { get; set; }
	public string Address { get; set; }


	public override string ToString()
	{
		return Dump.DumpType(this);
	}
}
public class StockItem
{
	public int Id { get; set; }
	public int Quantity { get; set; }
	public int ItemId { get; set; }


	public override string ToString()
	{
		return Dump.DumpType(this);
	}
}