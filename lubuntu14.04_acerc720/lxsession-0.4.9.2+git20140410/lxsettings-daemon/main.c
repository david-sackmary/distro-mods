/* main.c generated by valac 0.22.1, the Vala compiler
 * generated from main.vala, do not modify */

/* 
 *      Copyright 2013 Julien Lavergne <gilir@ubuntu.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <../lxsettings-daemon/settings-daemon.h>


#define TYPE_MAIN (main_get_type ())
#define MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MAIN, Main))
#define MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MAIN, MainClass))
#define IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MAIN))
#define IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MAIN))
#define MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MAIN, MainClass))

typedef struct _Main Main;
typedef struct _MainClass MainClass;
typedef struct _MainPrivate MainPrivate;
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _Main {
	GObject parent_instance;
	MainPrivate * priv;
};

struct _MainClass {
	GObjectClass parent_class;
};


static gpointer main_parent_class = NULL;
static gboolean main_persistent;
static gboolean main_persistent = FALSE;
static gchar* main_file;
static gchar* main_file = NULL;

GType main_get_type (void) G_GNUC_CONST;
enum  {
	MAIN_DUMMY_PROPERTY
};
gint main_main (gchar** args, int args_length1);
Main* main_new (void);
Main* main_construct (GType object_type);
static void main_finalize (GObject* obj);

static const GOptionEntry MAIN_option_entries[3] = {{"file", 'f', 0, G_OPTION_ARG_STRING, &main_file, "path of the configuration file", "NAME"}, {"persistent", 'p', 0, G_OPTION_ARG_NONE, &main_persistent, "reload configuration on file change", NULL}, {NULL}};

gint main_main (gchar** args, int args_length1) {
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	GError * _inner_error_ = NULL;
	_tmp0_ = main_file;
	if (_tmp0_ == NULL) {
		g_critical ("main.vala:34: Error, you need to specify a configuration file using -f" \
" argument. Exit");
		result = -1;
		return result;
	} else {
		GKeyFile* kf = NULL;
		GKeyFile* _tmp1_ = NULL;
		GKeyFile* _tmp8_ = NULL;
		gboolean _tmp9_ = FALSE;
		_tmp1_ = g_key_file_new ();
		kf = _tmp1_;
		{
			GKeyFile* _tmp2_ = NULL;
			const gchar* _tmp3_ = NULL;
			_tmp2_ = kf;
			_tmp3_ = main_file;
			g_key_file_load_from_file (_tmp2_, _tmp3_, G_KEY_FILE_NONE, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_KEY_FILE_ERROR) {
					goto __catch0_g_key_file_error;
				}
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch0_g_file_error;
				}
				_g_key_file_free0 (kf);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return 0;
			}
		}
		goto __finally0;
		__catch0_g_key_file_error:
		{
			GError* err = NULL;
			GError* _tmp4_ = NULL;
			const gchar* _tmp5_ = NULL;
			err = _inner_error_;
			_inner_error_ = NULL;
			_tmp4_ = err;
			_tmp5_ = _tmp4_->message;
			g_warning ("main.vala:47: %s", _tmp5_);
			g_critical ("main.vala:48: Problem when loading the configuration file. Exit");
			result = -1;
			_g_error_free0 (err);
			_g_key_file_free0 (kf);
			return result;
		}
		goto __finally0;
		__catch0_g_file_error:
		{
			GError* err = NULL;
			GError* _tmp6_ = NULL;
			const gchar* _tmp7_ = NULL;
			err = _inner_error_;
			_inner_error_ = NULL;
			_tmp6_ = err;
			_tmp7_ = _tmp6_->message;
			g_warning ("main.vala:53: %s", _tmp7_);
			g_critical ("main.vala:54: Problem when loading the configuration file. Exit");
			result = -1;
			_g_error_free0 (err);
			_g_key_file_free0 (kf);
			return result;
		}
		__finally0:
		if (_inner_error_ != NULL) {
			_g_key_file_free0 (kf);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return 0;
		}
		_tmp8_ = kf;
		settings_daemon_start (_tmp8_);
		_tmp9_ = main_persistent;
		if (_tmp9_ == FALSE) {
			result = 0;
			_g_key_file_free0 (kf);
			return result;
		} else {
			result = 0;
			_g_key_file_free0 (kf);
			return result;
		}
		_g_key_file_free0 (kf);
	}
}


int main (int argc, char ** argv) {
	g_type_init ();
	return main_main (argv, argc);
}


Main* main_construct (GType object_type) {
	Main * self = NULL;
	self = (Main*) g_object_new (object_type, NULL);
	return self;
}


Main* main_new (void) {
	return main_construct (TYPE_MAIN);
}


static void main_class_init (MainClass * klass) {
	main_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = main_finalize;
}


static void main_instance_init (Main * self) {
}


static void main_finalize (GObject* obj) {
	Main * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_MAIN, Main);
	G_OBJECT_CLASS (main_parent_class)->finalize (obj);
}


GType main_get_type (void) {
	static volatile gsize main_type_id__volatile = 0;
	if (g_once_init_enter (&main_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Main), 0, (GInstanceInitFunc) main_instance_init, NULL };
		GType main_type_id;
		main_type_id = g_type_register_static (G_TYPE_OBJECT, "Main", &g_define_type_info, 0);
		g_once_init_leave (&main_type_id__volatile, main_type_id);
	}
	return main_type_id__volatile;
}



