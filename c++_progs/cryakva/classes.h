class Cryak {
protected:
	const char *name;
	int weight;
	int hunted_count;
	Cryak *next;
public:
	friend class Lake;
	Cryak();
	virtual ~Cryak();
	virtual void Show_Info() const = 0;
};

class Hohl_cryak : public Cryak {
	int swim;
	const char *home;
	int stamina;
	const char *beak_color;
public:
	Hohl_cryak();
	virtual ~Hohl_cryak();
	virtual void Show_Info() const;
};

class Mram_chirk : public Cryak {
	int fly;
	char *tail_shape;
	int height;
public:
	Mram_chirk();
	virtual ~Mram_chirk();
	virtual void Show_Info() const;
};

class Kamen : public Cryak {
	int clev;
	int wingspan;
	const char sex;
public:
	Kamen();
	virtual ~Kamen();
	virtual void Show_Info() const;
};

class Blue_chirok : public Cryak {
	int swim;
	char *wing_shape;
	char *hobby;
public:
	Blue_chirok();
	virtual ~Blue_chirok();
	virtual void Show_Info() const;
};

class Mada_cryakva : public Cryak {
	int fly;
	int width;
	char *tail_shape;
public:
	Mada_cryakva();
	virtual ~Mada_cryakva();
	virtual void Show_Info() const;
};

class Krohali : public Cryak {
	int run;
	char *eye_color;
	char *tail_shape;
public:
	Krohali();
	virtual ~Krohali();
	virtual void Show_Info() const;
};

class Lake {
	Cryak *head;
	int size_list;
public:
	Lake();
	~Lake();
	int get_size() const;
	void add_list(Cryak *node);
	void print_list(); 
};
