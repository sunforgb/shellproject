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
	virtual int escape(const int lake_id) const = 0;
	virtual int get_unique_id() const = 0;
	virtual void Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const = 0;
	void hunted_count_inc();
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
	virtual int escape(const int lake_id) const;
	virtual void Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const;
	virtual int get_unique_id() const;
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
	virtual int escape(const int lake_id) const;
	virtual void Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const;
	virtual int get_unique_id() const;
};

class Kamen : public Cryak {
	int clev;
	int wingspan;
	char sex;
public:
	Kamen();
	virtual ~Kamen();
	virtual void Show_Info() const;
	virtual int get_fly() const;
	virtual int get_swim() const;
	virtual int get_clev() const;
	virtual int get_run() const;
	virtual int get_home() const;
	virtual int escape(const int lake_id) const;
	virtual void Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const;
	virtual int get_unique_id() const;
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
	virtual int escape(const int lake_id) const;
	virtual void Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const;
	virtual int get_unique_id() const;
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
	virtual int escape(const int lake_id) const;
	virtual void Show_count_hunted_ducks (const int hunted_lake_1, const int hunted_lake_2) const;
	virtual int get_unique_id() const;
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
	virtual int escape(const int lake_id) const;
	virtual void Show_count_hunted_ducks (const int hunted_lake_1, const int hunted_lake_2) const;
	virtual int get_unique_id() const;
};

class Lake {
	Cryak *head;
	const char *name;
	const int lake_id;
	int size_list;
	int count_fly;
	int count_swim;
	int count_clev;
	int count_run;
	int count_home;
public:
	Lake(const char *tmp, const int id);
	~Lake();
	int get_size() const;
	int get_count_fly() const;
	int get_count_swim() const;
	int get_count_clev() const;
	int get_count_run() const;
	int get_count_home() const;
	void Show_Info() const;
	void add_list(Cryak *node);
	void print_list();
	int get_lake_id() const;
	Cryak* del_node(int i);
	int ducks_escape_try(Lake *first_lake, Lake *second_lake);
	void del_creative_cryak();
};

class Hunters {
	const int hunter_id;
public:
	Hunters(const int id);
	~Hunters();
	int hunt(Lake *first_lake,Lake *second_lake, Lake *farm, int &hunted_ducks) const;
};

class Creative_cryak : public Cryak {
	const char *name;
	int weight;
	int hunted_count;
	int fly;
	int swim;
public:
	Creative_cryak();
	virtual ~Creative_cryak();
	virtual void Show_Info() const;
	virtual int get_fly() const;
	virtual int get_swim() const;
	virtual int get_clev() const;
	virtual int get_run() const;
	virtual int get_home() const;
	virtual int escape(const int lake_id) const;
	virtual void Show_count_hunted_ducks (const int hunted_lake_1, const int hunted_lake_2) const;
	virtual int get_unique_id () const;
};
