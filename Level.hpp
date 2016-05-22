



#ifndef SOLEIL_LEVEL__HPP
#define SOLEIL_LEVEL__HPP
# include <iostream>

# include <osg/Group>
# include <osg/Geometry>

namespace Soleil
{
  class LevelReader;
 
  class NextLevelZone : public osg::Geometry
  {
  public:
    static const char *ClassName;
    
  public:
    NextLevelZone() {}
    virtual ~NextLevelZone(void) {}

    virtual const char *className() const override
    {
      return NextLevelZone::ClassName;
    }
    
  };

  
  class Level : public osg::Group
  {
  public:
    Level(osg::ref_ptr<osg::Group> root);
    virtual ~Level(void);

  public:
    osg::Vec3	startingPosition() const;
    osg::Vec3	startingOrientation() const;
    bool	nextLevel(osg::Node *node) const
    {
      for (auto it = _nextLevelZones.cbegin(); it != _nextLevelZones.cend(); ++it) {
	if (*it == node)
	  {
	    std::cout << "VERS LA SORTIEEEEEE !"  << "\n";
	    return true;
	  }
      }
      return false;
    }


  protected:
    osg::ref_ptr<osg::Group>	_root;
    osg::Vec3			_startingPosition;
    osg::Vec3			_startingOrientation;
    
  protected:
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array();
    osg::ref_ptr<osg::Vec2Array> texcoords2 = new osg::Vec2Array();
    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    osg::ref_ptr<osg::Group> scene = new osg::Group;

    std::vector<osg::ref_ptr<osg::Geometry>>	_nextLevelZones;
    
    friend Soleil::LevelReader;
  };

  
  
}  // Soleil

#endif
