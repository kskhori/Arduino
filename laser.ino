#include <ros.h>
#include <std_msgs/Float32.h>

ros::NodeHandle node;
std_msgs::Float32 laser_dist1, laser_dist2, laser_dist3, laser_angle;

ros::Publisher pub1("laser_d1", &laser_dist1);
ros::Publisher pub2("laser_d2", &laser_dist2);
ros::Publisher pub3("laser_d3", &laser_dist3);
ros::Publisher pub4("laser_th", &laser_angle);

const int PIN_ANALOG_INPUT1 = 4;
const int PIN_ANALOG_INPUT2 = 5;
const int PIN_ANALOG_INPUT3 = 6;

void setup()
{
  node.initNode();
  node.advertise(pub1);
  node.advertise(pub2);
  node.advertise(pub3);
  node.advertise(pub4);
}

void loop()
{
  int i1 = analogRead( PIN_ANALOG_INPUT1 );
  int i2 = analogRead( PIN_ANALOG_INPUT2 );
  int i3 = analogRead( PIN_ANALOG_INPUT3 );
  float f1 = i1 * 5.0 / 1023.0;
  float f2 = i2 * 5.0 / 1023.0;
  float f3 = i3 * 5.0 / 1023.0;
  float pos1 = -f1* 400/5 + 597;
  float pos2 = -f2* 400/5 + 597;
  float pos3 = -f3* 400/5 + 597;
  float angle = (atan2((pos2-pos1),30.0))*180/PI;
  // Serial.println( pos ) &laser_dist;

 
  laser_dist1.data = pos1;
  pub1.publish(&laser_dist1);
  laser_dist2.data =  pos2;
  pub2.publish(&laser_dist2);
  laser_dist3.data =  pos3;
  pub3.publish(&laser_dist3);
  laser_angle.data =  angle;
  pub4.publish(&laser_angle);
  node.spinOnce();
  delay( 100 ); 
  }
