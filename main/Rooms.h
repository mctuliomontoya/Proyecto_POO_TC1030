#ifndef Rooms_h
#define Rooms_h


class Rooms {
    protected:
        string desctription;
    public:
        Rooms();
        Rooms(string);
        // virtual void showDesc();
};

Rooms::Rooms()   {
    desctription = "N/A";
}

Rooms::Rooms(string _d)  {
    desctription = _d;
}

#endif