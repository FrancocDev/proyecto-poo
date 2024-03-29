#ifndef ENUMDEFINITIONS_H
#define ENUMDEFINITIONS_H

// No modificar orden porque se usa para ciclos
enum ArrayTypes {
	CLIENT,
	PRODUCT,
	SELLER,
	ORDER
};

enum OrderParams{
	SELL_ID,
	SELL_CLIENT,
	SELL_SELLER,
	SELL_DATE,
};

enum ProductParams{
	PRODUCT_ID,
	PRODUCT_NAME,
	PRODUCT_BRAND,
	PRODUCT_PRICE,
	PRODUCT_QUANTITY
};

enum SellerParams{
	SELLER_ID,
	SELLER_NAME,
	SELLER_PHONE,
	SELLER_EMAIL,
};

enum ClientParams{
	CLIENT_ID,
	CLIENT_NAME,
	CLIENT_PHONE,
	CLIENT_ADDRESS,
	CLIENT_CITY,
	CLIENT_EMAIL,
	CLIENT_BIRTHDAY
};
#endif

