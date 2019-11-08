#ifndef EVE_CONTAINER__EH
#define EVE_CONTAINER__EH

struct Container_e {
    Container_e * prev = nullptr;
    Container_e * next = nullptr;

    Container_e() = default;
    Container_e(Container_e * prev, Container_e * next);
    ~Container_e();
};


#endif //EVE_CONTAINER__EH
