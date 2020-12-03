#include<ostream>

struct Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class LinkedList
{
private:
	int count;
	Node* head;
	Node* tail;

public:
	LinkedList() : count(0), head(nullptr), tail(nullptr) {}
	LinkedList(const LinkedList& list);
	~LinkedList();

private:
	bool indexValid(int index);
	Node* extractHeadNode();
	Node* extractTailNode();
	Node* extractNode(int index);
	void insertHeadNode(Node* node);
	void insertTailNode(Node* node);
	void insertNode(int index, Node* node);
public:
	int length();

	bool addToHead(int element);

	bool addToTail(int element);

	bool add(int index, int element);

	int get(int index);

	bool set(int index, int element);

	int& operator[](int index);

	void operator += (int);

	LinkedList& operator=(const LinkedList& list);

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList list);

	/// <summary>
	/// óäàëèòü íà÷àëî ñïèñêà
	/// </summary>
	/// <returns>çíà÷åíèå ýëåìåíòà, ñòîÿâøåãî â íà÷àëå</returns>
	int extractHead();

	/// <summary>
	/// óäàëèòü õâîñò ñïèñêà
	/// </summary>
	/// <returns>çíà÷åíèå ýëåìåíòà, ñòîÿâøåãî â êîíöå</returns>
	int extractTail();

	/// <summary>
	/// óäàëèòü ýëåìåíò, ñòîÿùèé íà ìåñòå index
	/// </summary>
	/// <returns>çíà÷åíèå ýëåìåíòà, ñòîÿâøåãî íà ìåñòå index</returns>
	int extract(int index);

	/// <summary>
	/// óäàëèòü ýëåìåíò
	/// </summary>
	/// <param name="">èíäåêñ óäàëÿåìîãî ýëåìåíòà</param>
	void operator-=(int index);

	/// <summary>
	/// ïîèñê ýëåìåíòà
	/// </summary>
	/// <param name="">çíà÷åíèå èñêîìîãî</param>
	/// <returns>-1, åñëè ýëåìåíòà â ñïèñêå íåò</returns>
	int indexOf(int element);

	/// <summary>
	/// ñîäåðæèòñÿ ëè ýëåìåíò â ñïèñêå. â ôóíêöèè íóæíî îáîéòèñü îäíîé ñòðîêîé
	/// </summary>
	/// <param name="">çíà÷åíèå ýëåìåíòà</param>
	bool contains(int element);

	/// <summary>
	/// ïîìåíÿòü äâà ýëåìåíòà ìåñòàìè.
	/// Ïåðåïèñûâàòü çíà÷åíèÿ ýëåìåíòîâ íåëüçÿ.
	/// Ìîæíî òîëüêî ìåíÿòü çíà÷åíèÿ ïîëåé next.
	/// </summary>
	/// <param name="">èíäåêñ ïåðâîãî ýëåìåíòà</param>
	/// <param name="">èíäåêñ âòîðîãî ýëåìåíòà</param>
	/// <returns>false - åñëè èíäåêñû áûëè íåêîððåêòíû</returns>
	bool swap(int, int);
};

