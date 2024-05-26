#include "functions.h"
#include "circle.h"
#include "rectangle.h"
#include "complexshape.h"
#include "shape.h"

sf::Vector2f rotate(const sf::Vector2f &v, float angle_rad)
{
	const float cs = std::cos(angle_rad);
	const float sn = std::sin(angle_rad);

	return { v.x*cs - v.y*sn, v.x*sn + v.y*cs };
}

void updateTexture(sf::Texture &t, const CSG2D::Shape &s, const sf::Color &foreground_color, const sf::Color &background_color)
{
	const auto tex_size = t.getSize();
	std::vector<sf::Uint8> tex_data(tex_size.x*tex_size.y*4u, 0u);
	const sf::Vector2f center = sf::Vector2f(tex_size)/2.f - sf::Vector2f(0.5f, 0.5f);
    for(std::size_t py = 0u; py < tex_size.y; ++py)
    {
	    for(std::size_t px = 0u; px < tex_size.x; ++px)
	    {
	        auto pos = sf::Vector2f(px, py) - center;
	        pos.y = -pos.y;
	        
	        const auto color = s.isIn(pos) ? foreground_color : background_color;

	        const std::size_t pi = py*tex_size.x + px;
	        const auto i = pi*4u;
	        tex_data[i] = color.r;
	        tex_data[i + 1u] = color.g;
	        tex_data[i + 2u] = color.b;
	        tex_data[i + 3u] = color.a;
	    }
    }
    t.update(tex_data.data());
}

std::shared_ptr<CSG2D::Shape> createCSG2DScene()
{
	std::shared_ptr<CSG2D::Shape> shp;
	std::shared_ptr<CSG2D::Shape> PlusPlus;
	std::shared_ptr<CSG2D::Shape> C;
	std::shared_ptr<CSG2D::Shape> P;
	std::shared_ptr<CSG2D::Shape> half;
	std::shared_ptr<CSG2D::Shape> K;
	auto Csquare = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(140.0, 300.0), 3.14/4, sf::Vector2f(160.0, 160.0));
	auto Ccircle = std::make_shared<CSG2D::Circle>(sf::Vector2f(0.f, 300.f), 0.0, 90.f);
	auto Ccircle2 = std::make_shared<CSG2D::Circle>(sf::Vector2f(0.f, 300.f), 0.0, 180.f);
	auto plusRectangle1 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(100.0, 300.0), 0, sf::Vector2f(30.0, 100.0));
	auto plusRectangle2 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(100.0, 300.0), 0, sf::Vector2f(100.0, 30.0));
	auto plusRectangle3 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(210.0, 300.0), 0, sf::Vector2f(30.0, 100.0));
	auto plusRectangle4 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(210.0, 300.0), 0, sf::Vector2f(100.0, 30.0));
	auto Pcircle = std::make_shared<CSG2D::Circle>(sf::Vector2f(-200.f, -100.f), 0.0, 50.f);
	auto PRectangle1 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(-300.0, -100.0), 0, sf::Vector2f(200.0, 100.0));
	auto Pcircle2 = std::make_shared<CSG2D::Circle>(sf::Vector2f(-200.f, -100.f), 0.0, 100.f);
	auto PRectangle2 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(-300.0, -100.0), 0, sf::Vector2f(200.0, 200.0));
	auto PRectangle3 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(-220.0, -150.0), 0, sf::Vector2f(50.0, 300.0));
	auto KRectangle1 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(220.0, -150.0), 0, sf::Vector2f(50.0, 300.0));
	auto KRectangle2 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(220.0, -150.0), 0.66*3.14/3, sf::Vector2f(50.0, 450.0));
	auto KRectangle3 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(220.0, -150.0), 2.33*3.14/3, sf::Vector2f(50.0, 450.0));
	auto KRectangle4 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(-100.0, -150.0), 0, sf::Vector2f(590.0, 600.0));
	auto KRectangle5 = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(620.0, -150.0), 0, sf::Vector2f(590.0, 600.0));
	PlusPlus = plusRectangle1->Union(plusRectangle2)->Union(plusRectangle3)->Union(plusRectangle4);
	C = Ccircle2->Difference(Ccircle)->Difference(Csquare);
	half = Pcircle->Difference(PRectangle1);
	P = Pcircle2->Difference(half)->Difference(PRectangle2)->Union(PRectangle3);
	K = KRectangle1->Union(KRectangle2)->Union(KRectangle3)->Difference(KRectangle4)->Difference(KRectangle5);
	shp = C->Union(PlusPlus)->Union(P)->Union(K);
	
	return shp;
}
