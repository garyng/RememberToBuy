#include "stdafx.h"
#include "CategoryStorage.h"

CategoryStorage::CategoryStorage(const std::shared_ptr<ILogger>& logger): JsonStorage<Category>(logger)
{
}

std::string CategoryStorage::Filename() const
{
	return NAMEOF(Category)".json";
}

std::vector<Category> CategoryStorage::DefaultData() const
{
	return std::vector<Category>
	{
		{0, "Kids", "Porro quis molestias qui odio aut ipsam fugit."},
		{1, "Movies", "Ut est cumque hic iure et in eius."},
		{2, "Automotive", "Ad accusantium ipsa quisquam."},
		{3, "Beauty", "Ut sunt rerum incidunt quaerat voluptatibus voluptas ducimus optio modi."},
		{4, "Grocery", "Voluptatum quia non sed debitis sequi."},
		{5, "Industrial", "Aut consequuntur et dolor."},
		{6, "Sports", "Perferendis commodi velit est dolore temporibus."},
		{7, "Automotive", "Error modi rem fugiat quis aliquam."},
		{8, "Outdoors", "Magnam dolorem et sed quod."},
		{9, "Shoes", "Architecto voluptatem rerum facere iure ut velit officia."}
	};
}
