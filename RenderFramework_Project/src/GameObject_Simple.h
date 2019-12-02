#ifndef GameObject_Simple_H
#define GameObject_Simple_H

#include "MathEngine.h"
#include "GameObject.h"
class GraphicComponent;
class GameObject_Simple : public GameObject
{
public:
	GameObject_Simple(GraphicComponent* graphicsObject, uint32_t gameObjectID = -1);

	// Big four
	/*GameObject_Simple() = delete;
	GameObject_Simple(const GameObject_Simple&) = delete;
	GameObject_Simple& operator=(GameObject_Simple&) = delete;*/
	//virtual ~GameObject_Simple();

};


#endif

//--- End of File ------------------------------------------------------------
