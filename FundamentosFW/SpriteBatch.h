#pragma once
#include <gl\glew.h>
#include "Vertex.h"
#include <glm\glm.hpp>
#include <vector>


enum class GlyphSortType {
		NONE,
		FRONT_TO_BACK,
		BACK_TO_FRONT,
		TEXTURE
};

struct  Glyph {
	GLuint texture;
	float depth;
	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;
};

class RenderBatch {
public:
	RenderBatch(GLuint offset, 
				GLuint numVertixes,
				GLuint texture);
	GLuint _offset;
	GLuint _numVertixes;
	GLuint _texture;

};

class SpriteBatch
{
private:
	GLuint _vbo;
	GLuint _vao;
	std::vector<Glyph*> _glyphs;
	std::vector<RenderBatch>
		_renderBatches;
	void createVertexArray();
	void sortGlyph();
	GlyphSortType _sortType;
	void createRenderbatches();
public:
	SpriteBatch();
	~SpriteBatch();
	void init();
	void begin(
		GlyphSortType 
		sortType = GlyphSortType::TEXTURE);
	void end();
	void draw(const glm::vec4& destRect, 
				const glm::vec4& uvRect);
	void renderBatch();
};
