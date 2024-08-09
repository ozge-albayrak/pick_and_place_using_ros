// Auto-generated. Do not edit!

// (in-package rumba_msg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class BatteryStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.percentage_battery = null;
      this.location_x = null;
      this.location_y = null;
      this.orientation_theta = null;
      this.brushes_up = null;
      this.debug_message = null;
    }
    else {
      if (initObj.hasOwnProperty('percentage_battery')) {
        this.percentage_battery = initObj.percentage_battery
      }
      else {
        this.percentage_battery = 0;
      }
      if (initObj.hasOwnProperty('location_x')) {
        this.location_x = initObj.location_x
      }
      else {
        this.location_x = 0.0;
      }
      if (initObj.hasOwnProperty('location_y')) {
        this.location_y = initObj.location_y
      }
      else {
        this.location_y = 0.0;
      }
      if (initObj.hasOwnProperty('orientation_theta')) {
        this.orientation_theta = initObj.orientation_theta
      }
      else {
        this.orientation_theta = 0.0;
      }
      if (initObj.hasOwnProperty('brushes_up')) {
        this.brushes_up = initObj.brushes_up
      }
      else {
        this.brushes_up = false;
      }
      if (initObj.hasOwnProperty('debug_message')) {
        this.debug_message = initObj.debug_message
      }
      else {
        this.debug_message = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type BatteryStatus
    // Serialize message field [percentage_battery]
    bufferOffset = _serializer.int64(obj.percentage_battery, buffer, bufferOffset);
    // Serialize message field [location_x]
    bufferOffset = _serializer.float64(obj.location_x, buffer, bufferOffset);
    // Serialize message field [location_y]
    bufferOffset = _serializer.float64(obj.location_y, buffer, bufferOffset);
    // Serialize message field [orientation_theta]
    bufferOffset = _serializer.float64(obj.orientation_theta, buffer, bufferOffset);
    // Serialize message field [brushes_up]
    bufferOffset = _serializer.bool(obj.brushes_up, buffer, bufferOffset);
    // Serialize message field [debug_message]
    bufferOffset = _serializer.string(obj.debug_message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type BatteryStatus
    let len;
    let data = new BatteryStatus(null);
    // Deserialize message field [percentage_battery]
    data.percentage_battery = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [location_x]
    data.location_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [location_y]
    data.location_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [orientation_theta]
    data.orientation_theta = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [brushes_up]
    data.brushes_up = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [debug_message]
    data.debug_message = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.debug_message);
    return length + 37;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rumba_msg/BatteryStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8553ab09064a977637e06a24726e1227';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 percentage_battery
    float64 location_x
    float64 location_y
    float64 orientation_theta
    bool brushes_up
    string debug_message
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new BatteryStatus(null);
    if (msg.percentage_battery !== undefined) {
      resolved.percentage_battery = msg.percentage_battery;
    }
    else {
      resolved.percentage_battery = 0
    }

    if (msg.location_x !== undefined) {
      resolved.location_x = msg.location_x;
    }
    else {
      resolved.location_x = 0.0
    }

    if (msg.location_y !== undefined) {
      resolved.location_y = msg.location_y;
    }
    else {
      resolved.location_y = 0.0
    }

    if (msg.orientation_theta !== undefined) {
      resolved.orientation_theta = msg.orientation_theta;
    }
    else {
      resolved.orientation_theta = 0.0
    }

    if (msg.brushes_up !== undefined) {
      resolved.brushes_up = msg.brushes_up;
    }
    else {
      resolved.brushes_up = false
    }

    if (msg.debug_message !== undefined) {
      resolved.debug_message = msg.debug_message;
    }
    else {
      resolved.debug_message = ''
    }

    return resolved;
    }
};

module.exports = BatteryStatus;
