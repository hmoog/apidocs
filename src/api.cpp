/*! \file */ 
/** \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */

/**
 * @brief %Game Callbacks
 */
namespace Callback {
    public:
        /**
         * Binds a new callback.
         *
         * @param arg1    callback name
         *
         * @param arg2    Params.
         *
         * Example: Callback.Bind("GameStart", function() print("Game has started!") end)
         **/
        function void Bind(string arg1, object arg2) {}

        /**
         * Unbinds a callback
         *
         * @param arg1  Set which callback should be unbinded.
         *
         * @param arg2         Params.
         **/
        function int Unbind(string arg1, object arg2) {}

        /**
         * Gets callbacks.
         *
         **/
        function object GetCallbacks(string arg) {}

        /**
         * Triggers a callback list.
         *
         **/
        function void Trigger(string arg1, object arg2) {}

        /**
         * Prioritizes the bind of .string.
         *
         **/
        function void PriorityBind(string arg1, object arg2) {}

        
        /*! Callback enums. */
        enum {
            Animation, /*!< triggered when the unit does an animation */
            ApplyBuff, /*!< triggered when a buff is applied to the unit */
            ApplyParticle, /*!< triggered when a particle is applied to unit */
            Bugsplat, /*!< triggered when user bugsplats */
            CastSpell, /*!< triggered when unit casts a spell */
            CreateObj, /*!< triggered when an object is created */
            DeleteObj, /*!< triggered when an object is deleted */
            Draw, /*!< triggered every FRAME */
            Exit, /*!< triggered on exit */
            GameStart, /*!< triggered when the game starts */
            GameTick, /*!< different to Tick */
            IssueOrder, /*!< triggered on IssueOrder */
            Load, /*!< triggered when cloudrop injects // not when the game begins */
            NewPath, /*!< triggered when unit makes a new path */
            Notify, /*!< triggered on a new event */
            ProcessAttack, /*!< triggered when an attack is being made */
            ProcessSpell, /*!< triggered when a spell is being cast */
            RecvChat, /*!< triggered when receiving a message in chat */
            RecvPacket, /*!< triggered when receiving a packet */
            RemoveBuff, /*!< triggered when a buff is removed from unit */
            Reset, /*!< triggered every draw reset */
            SendChat, /*!< triggered when sending a message in chat */
            SendPacket, /*!< triggered when sending a packet */
            Tick, /*!< triggered every TICK */
            UnLoad, /*!< triggered when user unloads cloudrop */
            UpdateBuff, /*!< triggered when unit's buff is updated */
            UpdateObj, /*!< triggered on object update */
            WndMsg, /*!< triggered when a key is/has been pressed */

        };
}

namespace Game {
    public:
        /**
         * enables / disables if keyboard inputs get propagated to the game
         *
         * @param enabled  flag indicating if the input should be allowed or not
         **/
        function AllowKeyInput(bool enabled) {}

        /**
         * enables / disables if mouse inputs get propagated to the game
         *
         * @param enabled  flag indicating if the input should be allowed or not
         */
        function AllowCameraInput(bool enabled) {}

        /**
         * Blocks the order.
         */
        function void BlockOrder() {}

        /**
         * Blocks the spell.
         */
        function void BlockSpell() {}

        /**
         * Buys the item with the id set.
         *
         * @param id     example: 3053
         *
         * code example     myHero:BuyItem(3053)
         */
        function void BuyItem(string id) {}

        /**
         * Does an emote.
         */
        function void DoEmote(unsigned long arg1) {}

        /**
         * Enables/disables AntiAFK function.
         */
        function void EnableAntiAFK(bool arg1) {}

        /**
         * Returns Game Region as a string
         */
        function string GetGameRegion() {}

        /**
         * Returns Game Version as a string
         */
        function string GetGameVersion() {}

        class Chat {
            public:
                /**
                 * Blocks the chat
                 */
                function Block() {}

                /**
                 * Print a message in chat
                 *
                 * @param arg   string
                 *
                 * Prints arg in chat
                 */
                function Print(string arg) {}

                /**
                 * Sends a message to the chat
                 *
                 * @param arg   string
                 *
                 * Sends arg in chat
                 */
                function Send(string arg) {}
        }

}

/**
 * @brief functions that do not interfere with the game in any way but are commonly used by a multitude of scripts
 */
namespace Utility {
    public:
        /**
         * delays the execution of a function
         *
         * @param  func       the function that gets executed after the given timeout
         * @param  timeout    delay in milliseconds that the function will wait before execution
         * @param  arguments  [optional] table of arguments that get passed as function parameters
         *
         * @return \ref Utility.Timeout object related to the function
         */
        function SetTimeout(function func, int delay timeout = 0, table arguments = {}) {}

        /**
         * @brief Base64 functions
         */

        class Base64 {
            public:
                /**
                 * @param  string       the function will base64 Decode the string
                 */
                function Decode(arguments string) {}

                /**
                 * @param  string       the function will base64 Encode the string
                 */
                function Encode(arguments string) {}
        }

        /**
         * @brief timeouts generated by SetTimeout
         * @see SetTimeout
         */
        class Timeout {
            public:
                /**
                 * removes the given timeout object, so the "planned" function does not get executed
                 */
                function clear() {}
        }
}

/**
 * @brief functions related with your window / pc.
 */
namespace Window {
    public:
        /**
         * Returns cursos current position as a 2D Vector.
         *
         * Example      print(Window.GetCursorPos()) -> Should print something like this (507, 330).
         **/
        function Vector2 GetCursorPos() {}

        /**
         * Returns window current position as a 2D Vector.
         *
         * Example      print(Window.GetWindowPos()) -> Should print something like this (0, 0).
         **/
        function Vector2 GetWindowPos() {}

        /**
         * Returns window size as a 2D Vector. ()
         *
         * Example      print(Window.GetWindowSize()) -> Should print window resolution.
         **/
        function Vector2 GetWindowSize() {}

        class Clipboard {
            public:
            /**
             * Returns the text you have in your clipboard.
             **/
            function GetText() {}

            /**
             * Returns the text you have in your clipboard.
             *
             * @param arg    text to set in the clipboard.
             **/
            function void SetText(string arg) {}
        }
}

/**
 * @brief Menu related functions.
 */
namespace MenuConfig {
    public:
        /**
         * Creates a Boolean-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         * @param  DefVal       default value - true/false [optional]
         * @param  callback       callback function [optional]
         * @param  ForceDefault       Force default value - true/false [optional]
         */
        function Boolean(object id, object text, object DefVal, function callback, object ForceDefault) {}

        /**
         * Creates a Button-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         * @param  callback       Force callback function [optional]
         */
        function Button(object id, object text, function callback) {}

        /**
         * Creates a ColorPick-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         * @param  DefVal       default value - true/false [optional]
         * @param  callback       callback function [optional]
         * @param  ForceDefault       Force default value - true/false [optional]
         */
        function ColorPick(object id, object text, object DefVal, function callback, object ForceDefault) {}

        /**
         * Creates a DropDown-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         * @param  DefVal       default value - boolean
         * @param  arguments       table containing DropDown options.
         * @param  callback       callback function [optional]
         * @param  ForceDefault       Force default value - true/false [optional]
         */
        function DropDown(object id, object text, object DefVal, table arguments = {}, function callback, object ForceDefault) {}

        /**
         * Creates an Info-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         */
        function Info(object id, object text) {}

        /**
         * Creates a KeyBinding-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         * @param  Key       key string
         * @param  callback       callback function [optional]
         * @param  ForceDefault       Force default value - true/false [optional]
         */
        function KeyBinding(object id, object text, object Key, function callback, object ForceDefault) {}

        /**
         * Creates a Sub-Menu in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         */
        function Menu(object id, object text) {}

        /**
         * Creates a Number-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         * @param  DefVal       default value - boolean
         * @param  MinValue       Minimum Value. [optional]
         * @param  MaxValue       Maximum Value. [optional]
         * @param  callback       callback function [optional]
         * @param  ForceDefault       Force default value - true/false [optional]
         */
        function Number(object id, object text, object DefVal, int MinValue, int MaxValue, function callback, object ForceDefault) {}

        /**
         * Creates a Section-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         */
        function Section(object id, object text) {}

        /**
         * Creates a Separator-Field in your Menu.
         *
         */
        function Separator() {}

        /**
         * Creates a Slider-Field in your Menu.
         *
         * @param  id       id of menu
         * @param  text       text to display in menu
         * @param  DefVal       default value - boolean
         * @param  MinValue       Minimum Value. 
         * @param  MaxValue       Maximum Value. 
         * @param  step         slider step (1, 10 , 3, 0.3) [optional]
         * @param  callback       callback function [optional]
         * @param  ForceDefault       Force default value - true/false [optional]
         */
        function Slider(object id, object text, object DefVal, int MinValue, int MaxValue, int step, function callback, object ForceDefault) {}

        /**
         * Creates a TargetSelector-Field in your Menu.
         *
         * @param  id       Id of menu
         * @param  text       Text to display in menu
         * @param  Mode       TS (Target Selector) Mode [optional]
         * @param  range       Range for TS [optional]
         * @param  DmgType       TS Damage Type [optional]
         * @param  FocusSelected       Stands a boolean value [optional]
         * @param  OwnTeam       Boolean for team checking. [optional]
         */
        function TargetSelector(object id, object text, int Mode, int range, string DmgType, bool FocusSelected, bool OwnTeam) {}
}

/**
 * @brief Keyboard related functions.
 */
namespace Keyboard {
    public:
        /**
         * Checks if Key WAS pressed.
         *
         * @param  id       KeyCode/Name/string
         */
        function IsKeyDown(int id) {}

        /**
         * Checks if Key IS pressed.
         *
         * @param  id       KeyCode/Name/string
         */
        function IsKeyPressed(int id) {}

        /**
         * Checks if Keys WERE pressed.
         *
         * @param  id       KeyCode/Name/string
         */
        function KeysDown(object id) {}

        /**
         * Return key code of string
         *
         * @param  id       KeyCode/Name/string
         */
        function StringToKeyCodes(int id) {}

        /**
         * Return Ascii with the given string
         *
         * @param  id       KeyCode/Name/string
         */
        function ToAscii(int id) {}

        /*! KeyCode enums. */
        enum KeyCode {
            numbers1To9,
            A,
            ADD,
            ALT,
            B,
            BACKSPACE,
            BACK_SLASH,
            BROWSER_BACK,
            BROWSER_FORWARD,
            C,
            CAPS_LOCK,
            CLOSE_BRACKET,
            COMMA,
            CTRL,
            D,
            DASH,
            DECIMAL_POINT,
            DELETE,
            DIVIDE,
            DOWN_ARROW,
            E,
            END,
            ENTERM,
            EQUAL,
            ESCAPE,
            F,
            F1,
            F10,
            F11,
            F12,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            FORWARD_SLASH,
            G,
            GRAVE_ACCENT,
            H,
            HOME,
            I,
            INSERT,
            J,
            K,
            L,
            LEFT_ARROW,
            LEFT_WINDOWS,
            M,
            MENU,
            MULTIPLY,
            N,
            NUMPAD_0,
            NUMPAD_1,
            NUMPAD_2,
            NUMPAD_3,
            NUMPAD_4,
            NUMPAD_5,
            NUMPAD_6,
            NUMPAD_7,
            NUMPAD_8,
            NUMPAD_9,
            NUM_LOCK,
            O,
            OPEN_BRACKET,
            P,
            PAGE_DOWN,
            PAGE_UP,
            PAUSE,
            PERIOD,
            Q,
            R,
            RIGHT_ARROW,
            RIGHT_WINDOWS,
            S,
            SCROLL_LOCK,
            SEMICOLON,
            SHIFT,
            SINGLE_QUOTE,
            SPACE,
            SUBTRACT,
            T,
            TAB,
            U,
            UP_ARROW,
            V,
            W,
            X,
            Y,
            Z,
        }
}

/**
 * @brief Core functions.
 */
namespace Core {
    public:
        /**
         * Returns Build date as a string. Example: Jun 30 2016
         **/
        function GetBuildDate() {}

        /**
         * Returns Old Username as a string.
         **/
        function GetOldUserName() {}

        /**
         * Returns Tick count.
         **/
        function GetTickCount() {}

        /**
         * Returns User.
         **/
        function GetUser() {}

        /**
         * Returns User Id.
         **/
        function GetUserId() {}

        class Console {
            public:
                /**
                 * Returns Console Pos (2dVector).
                 **/
                function vector2 GetPos() {}

                /**
                 * Hides console.
                 **/
                function Hide() {}

                /**
                 * Shows console.
                 **/
                function Show() {}

                /**
                 * Sets Position.
                 *
                 * @param arg1  x pos.
                 *
                 * @param arg2  y pos.
                 **/
                function vector2 SetPos(unsigned int arg1, unsigned int arg2) {}
        }
}

/**
 * @brief Documentation function.
 */
namespace Documentation {
    public:
        /**
         * Generates the documentation of the API set
         *
         * @param arg   API to generate doc from. Example -> print(Documentation.Generate(Game)) -- Will print everything related to Game namespace.
         **/
        function Generate(object arg) {}
}
