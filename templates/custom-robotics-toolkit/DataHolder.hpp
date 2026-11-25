
template <typename T>
class DataHolder {
public:
    DataHolder(T val, T min, T max) 
    : minValue(min), maxValue(max) {
        if (val >= minValue && val <= maxValue) {
            storedValue = val; 
        } else if (val > maxValue) {
            std::cout << "WARNING: val is too high! Setting value to max!" << std::endl;
            storedValue = minValue;
        } else { // val < min 
            std::cout << "WARNING: val is too low! Setting value to min!" << std::endl;
            storedValue = minValue;
        }
    }
    void setValue(T newValue) {
        if (newValue >= minValue && newValue <= maxValue) {
            storedValue = newValue;
        } else if (newValue > maxValue) {
            std::cout << "WARNING: val is too high! Setting value to max!" << std::endl;
            storedValue = maxValue;
        } else { // newValue < minValue 
            std::cout << "WARNING: val is too low! Setting value to min!" << std::endl;
            storedValue = minValue;
        }
    }
    T getValue() const {
        return storedValue;
    }
private:
    T storedValue;
    T maxValue;
    T minValue;
};

template <>
class DataHolder<std::string> {
public:
    DataHolder(std::string val) : storedValue(val) {}
    void setValue(std::string newString) {
        storedValue = newString;
    }
    std::string getValue() const {
        return storedValue;
    }
private:
    std::string storedValue;

};
