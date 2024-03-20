template<class T>
class List<T>::Const_Iterator {
public:
	// Constructor
	Const_Iterator(const List<T>*, D_Node*, size_t);

	// Class-member functions
	const T& operator * () const;
	const T* operator -> () const;
	Const_Iterator& operator ++ ();
	Const_Iterator operator++ (int);
	Const_Iterator& operator -- ();
	Const_Iterator operator-- (int);
	int operator - (const Const_Iterator&) const;
	bool operator == (const Const_Iterator&) const;
	bool operator != (const Const_Iterator&) const;

private:
	// Data fields
	const List<T>* parent;
	const D_Node* current;
	size_t offset;

	friend class List<T>;
};
