class List{
private:
	struct node{
	node *next;
	int val;
};
	node * head;
	node *current;
public:
	List();
	List(const List& l);
	List& operator=(const List& l);
	~List();
	void insert(int a);
	void goToHead();
	int getCurrentData();
	void advance();
	bool moreData();
};
