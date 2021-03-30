class Cryak {
protected:
	const char *name;
	int weight;
	int hunted_count;
	Cryak *next;
public:
	Cryak();
	virtual ~Cryak();
	friend class Lake;
	virtual void Show_Info() const = 0;
	virtual int get_fly() const = 0;
	virtual int get_swim() const = 0;
	virtual int get_clev() const = 0;
	virtual int get_run() const = 0;
	virtual int get_home() const = 0;
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
	virtual int get_fly() const;
	virtual int get_swim() const;
	virtual int get_clev() const;
	virtual int get_run() const;
	virtual int get_home() const;
};

class Mram_chirk : public Cryak {
	int fly;
	char *tail_shape;
	int height;
public:
	Mram_chirk();
	virtual ~Mram_chirk();
	virtual void Show_Info() const;
	virtual int get_fly() const;
	virtual int get_swim() const;
	virtual int get_clev() const;
	virtual int get_run() const;
	virtual int get_home() const;
};

class Kamen : public Cryak {
	int clev;
	int wingspan;
	const char sex;
public:
	Kamen();
	virtual ~Kamen();
	virtual void Show_Info() const;
	virtual int get_fly() const;
	virtual int get_swim() const;
	virtual int get_clev() const;
	virtual int get_run() const;
	virtual int get_home() const;
};

class Blue_chirok : public Cryak {
	int swim;
	char *wing_shape;
	char *hobby;
public:
	Blue_chirok();
	virtual ~Blue_chirok();
	virtual void Show_Info() const;
	virtual int get_fly() const;
	virtual int get_swim() const;
	virtual int get_clev() const;
	virtual int get_run() const;
	virtual int get_home() const;
};

class Mada_cryakva : public Cryak {
	int fly;
	int width;
	char *tail_shape;
public:
	Mada_cryakva();
	virtual ~Mada_cryakva();
	virtual void Show_Info() const;
	virtual int get_fly() const;
	virtual int get_swim() const;
	virtual int get_clev() const;
	virtual int get_run() const;
	virtual int get_home() const;
};

class Krohali : public Cryak {
	int run;
	char *eye_color;
	char *tail_shape;
public:
	Krohali();
	virtual ~Krohali();
	virtual void Show_Info() const;
	virtual int get_fly() const;
	virtual int get_swim() const;
	virtual int get_clev() const;
	virtual int get_run() const;
	virtual int get_home() const;
};

class Lake {
	Cryak *head;
	int size_list;
	int count_fly;
	int count_swim;
	int count_clev;
	int count_run;
	int count_home;
public:
	Lake();
	~Lake();
	int get_size() const;
	int get_count_fly() const;
	int get_count_swim() const;
	int get_count_clev() const;
	int get_count_run() const;
	int get_count_home() const;
	void add_list(Cryak *node);
	void print_list();
	Cryak* del_node(int i);
};

class Hunters {
	const char *name;
public:
	void hunt();
	void smash_duck();
	void chill();
};
