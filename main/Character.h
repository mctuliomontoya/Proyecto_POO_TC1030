#ifndef Character_h
#define Character_h

class Character{
    private:
        string name;
        int hP;
    public:
        Character();
        Character(string, int);
        string getName(){return name;};
        int getHp(){return hP;};
};

Character::Character()  {
    name = "Hero without name.";
    hP = 0;
}

Character::Character(string _name, int _hP) {
    name = _name;
    hP = _hP;
}

#endif