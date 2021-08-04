
const int theAnswer =42;

auto x = theAnswer;
auto y = &theAnswer;

template<typename T>
class TD; //TD == "Type Displayer"

TD<decltype(x)> xType;
TD<decltype(y)> yType;

int main()
{
	return 0;
}
